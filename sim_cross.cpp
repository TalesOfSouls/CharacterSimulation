#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../GameEngine/thread/Thread.h"
#include "../GameEngine/stdlib/simd/SIMD_Helper.h"

#if _WIN32
    #include "../GameEngine/platform/win32/FileUtils.cpp"
    #include "../GameEngine/platform/win32/Allocator.h"
#else
    #include "../GameEngine/platform/linux/FileUtils.cpp"
    #include "../GameEngine/platform/linux/Allocation.h"
#endif

#include "SimulationDefinitions.h"
#include "simulate_char.h"
#include "simulate_item.h"

#include "../GameServer/GameConsts.h"
#include "../GameEngine/models/mob/player/_player_class.h"
#include "../GameEngine/models/item/_equipment_slots.h"

int simd_step_size;
DatabaseConnection con;
PlayerXPRequirement* xp_requirement;
RarityDefinition* item_rarity;
MobLevelStats* mob_levels;
ItemLevelStats* item_levels;
EquipmentType* equipment_types;
EquipmentType** class_equipment_types;
EquipmentType** slot_equipment_types;
EquipmentType** class_slot_equipment_types;

void parse_config_file(const char *filename, Settings* config) {
    char file_path[MAX_PATH];
    relative_to_absolute(filename, file_path);

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        exit(EXIT_FAILURE);
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "classes", 7) == 0) {
            char *token = strtok(line + 8, ",");
            int index = 0;
            while (token != NULL && index < 30) {
                config->classes[index++] = atoi(token);
                token = strtok(NULL, ",");
            }

            config->classes_count = index;
        } else if (sscanf(line, "char_level %d", &config->char_level) == 1) {
        } else if (sscanf(line, "threads %d", &config->threads) == 1) {
        } else if (sscanf(line, "iterations %d", &config->iterations) == 1) {
        } else if (sscanf(line, "mutation_rate %f", &config->mutation_rate) == 1) {
        } else if (sscanf(line, "ranking_size %d", &config->ranking_size) == 1) {
        } else if (sscanf(line, "rand %d", &config->rand) == 1) {
            if (config->rand == 0) {
                config->rand = (int) time(NULL);
            }
        }
    }

    // @todo we might want to allow multiple threads even if only one or two classes are tested.
    //      However, this requires much more thinking
    if (config->threads > config->classes_count) {
        config->threads = config->classes_count;
    }

    fclose(file);
}

float calculate_dps(int cclass, CharacterBuild* build) {
    // @todo implement
    // @todo damage formula should depend on class
    // @todo damage should depend on opponents -> we need to simulate many different enemy mobs and then take the avg

    float str_mult;
    float int_mult;
    float acc_mult;
    float agi_mult;

    switch (cclass) {
        case 1: {
            str_mult = 1.2f;
            int_mult = 1.2f;
            acc_mult = 1.1f;
            agi_mult = 0.8f;
        } break;
        case 2: {
            str_mult = 0.9f;
            int_mult = 0.9f;
            acc_mult = 1.1f;
            agi_mult = 0.8f;
        } break;
        case 3: {
            str_mult = 1.0f;
            int_mult = 1.0f;
            acc_mult = 1.1f;
            agi_mult = 1.3f;
        } break;
        case 4: {
            str_mult = 1.1f;
            int_mult = 1.1f;
            acc_mult = 0.9f;
            agi_mult = 1.5f;
        } break;
        case 5: {
            str_mult = 1.3f;
            int_mult = 1.3f;
            acc_mult = 1.1f;
            agi_mult = 0.9f;
        } break;
        case 6: {
            str_mult = 1.4f;
            int_mult = 1.4f;
            acc_mult = 1.1f;
            agi_mult = 1.0f;
        } break;
        case 7: {
            str_mult = 1.2f;
            int_mult = 1.2f;
            acc_mult = 0.8f;
            agi_mult = 1.1f;
        } break;
        case 8: {
            str_mult = 1.1f;
            int_mult = 1.1f;
            acc_mult = 0.9f;
            agi_mult = 1.12f;
        } break;
        default: {
            str_mult = 1.5f;
            int_mult = 1.5f;
            acc_mult = 1.5f;
            agi_mult = 1.5f;
        }
    }

    return build->char_points.primary_stats.stat_str * str_mult
        + build->char_points.primary_stats.stat_int * int_mult
        + build->char_points.primary_stats.stat_acc * acc_mult
        + build->char_points.primary_stats.stat_agi * agi_mult;
}

float calculate_healing() {
    return 1.0f;
}

float calculate_health() {
    return 1.0f;
}

float calculate_resource() {
    return 1.0f;
}

float calculate_movement_speed() {
    return 1.0f;
}

// simulates a fight (by how much would the player win/lose?)
float simulate_fight() {
    return 1.0f;
}

THREAD_RETURN thread_func(void* arg)
{
    ThreadData* thr_data = (ThreadData*) arg;
    BuildResult* results = thr_data->results;

    float worst_dps = 0.0f;
    /*
    float worst_health = 0.0f;
    float worst_healing = 0.0f;
    float worst_resource = 0.0f;
    float worst_movement_speed = 0.0f;
    */

    //CharacterBuild new_build;

    CharacterBuild* new_build;
    if (simd_step_size == 16) {
        new_build = (CharacterBuild *) platform_alloc_aligned(sizeof(CharacterBuild), 64);
    } else if (simd_step_size == 8) {
        new_build = (CharacterBuild *) platform_alloc_aligned(sizeof(CharacterBuild), 32);
    } else if (simd_step_size == 4) {
        new_build = (CharacterBuild *) platform_alloc_aligned(sizeof(CharacterBuild), 16);
    } else {
        new_build = (CharacterBuild *) platform_alloc_aligned(sizeof(CharacterBuild), 4);
    }

    for (int i = 0; i < thr_data->config->iterations; i++) {
        for (int j = 0; j < thr_data->config->ranking_size; ++j) {
            //new_build = results[j].build;
            memcpy(new_build, &results[j].build, sizeof(CharacterBuild));

            // perform mutation
            mutate_char_build(new_build, (float) thr_data->config->mutation_rate, simd_step_size);
            mutate_items_build(new_build, (float) thr_data->config->mutation_rate);

            // perform calculations
            // handle dps
            float new_dps = calculate_dps(thr_data->config->classes[thr_data->char_class_index], new_build);
            if (new_dps > worst_dps) {
                int c;
                for (c = thr_data->config->ranking_size - 1; (c > 0 && results[c - 1].dps < new_dps); --c) {
                    if (c < thr_data->config->ranking_size - 1) {
                        results[c] = results[c - 1];
                    }
                }

                memcpy(&results[c].build, new_build, sizeof(CharacterBuild));

                //results[c].build = new_build;
                results[c].dps = new_dps;
                worst_dps = results[thr_data->config->ranking_size - 1].dps;
            }

            // handle health
            // @todo implement

            // handle healing
            // @todo implement

            // handle resource
            // @todo implement

            // handle movement_speed
            // @todo implement
        }
    }

    platform_aligned_free((void **) &new_build);

    pthread_exit(NULL);
}

int main() {
    if (max_avx512_supported() > 0) {
        simd_step_size = 16;
    } else if (max_avx256_supported() > 0) {
        simd_step_size = 8;
    } else if (max_sse_supported() > 0) {
        simd_step_size = 4;
    } else {
        simd_step_size = 1;
    }

    clock_t start = clock();

    // load settings
    Settings config;
    parse_config_file("settings.cfg", &config);
    srand(config.rand);

    // game data
    sqlite3 *db;
    sqlite3_open("./../build/simulation/TalesOfSouls.db", &db);

    xp_requirement = (PlayerXPRequirement *) malloc(sizeof(PlayerXPRequirement) * 100);
    item_rarity = (RarityDefinition *) malloc(sizeof(RarityDefinition) * RARITY_TYPE_SIZE);
    mob_levels = (MobLevelStats *) malloc(sizeof(MobLevelStats) * 200);
    item_levels = (ItemLevelStats *) malloc(sizeof(ItemLevelStats) * 99);
    equipment_types = (EquipmentType *) malloc(sizeof(EquipmentType) * 200);
    class_equipment_types = (EquipmentType **) calloc(PLAYER_CLASS_SIZE * 200, sizeof(EquipmentType *));
    slot_equipment_types = (EquipmentType **) calloc(EQUIPMENT_SLOT_SIZE * 200, sizeof(EquipmentType *));
    class_slot_equipment_types = (EquipmentType **) calloc(PLAYER_CLASS_SIZE * EQUIPMENT_SLOT_SIZE * 200, sizeof(EquipmentType *));

    // prepare data
    BuildResult* results = (BuildResult *) platform_alloc(config.classes_count * config.ranking_size * sizeof(BuildResult));

    printf("\nBuild Count: %d\n", config.classes_count * config.ranking_size * config.iterations);
    printf("Cache Size: %d\n", (int) (config.classes_count * config.ranking_size * sizeof(BuildResult)));
    printf(
        "Game Data Size %lld\n", (int64)
        sizeof(PlayerXPRequirement) * 100
        + sizeof(RarityDefinition) * RARITY_TYPE_SIZE
        + sizeof(MobLevelStats) * 200
        + sizeof(ItemLevelStats) * 99
        + sizeof(EquipmentType) * 200
        + sizeof(EquipmentType *) * PLAYER_CLASS_SIZE * 200
        + sizeof(EquipmentType *) * EQUIPMENT_SLOT_SIZE * 200
        + sizeof(EquipmentType *) * PLAYER_CLASS_SIZE * EQUIPMENT_SLOT_SIZE * 200
    );
    printf("\n");

    load_game_consts(
        &con,
        xp_requirement,
        item_rarity,
        mob_levels,
        item_levels,
        equipment_types,
        class_equipment_types,
        slot_equipment_types,
        class_slot_equipment_types
    );

    // @todo first simulate the creation of N enemy mobs to fight against
    //  dps should be min, max and avg since it depends on mob type

    // run threads
    Worker* worker = (Worker *) malloc(config.threads * sizeof(Worker));
    for (int j = 0; j < config.classes_count; j += config.threads) {
        ThreadData* thr_data = (ThreadData *) malloc(config.threads * sizeof(ThreadData));

        for (int i = 0; i < config.threads && j + i < config.classes_count; ++i) {
            thr_data[i].char_class_index = j + i;
            thr_data[i].config = &config;
            thr_data[i].results = (results + j * config.ranking_size + i * config.ranking_size);

            memset(&worker[i], 0, sizeof(Worker));
            thread_create(&worker[i], thread_func, &thr_data[i]);
            thread_stop(&worker[i]);
        }

        free(thr_data);
    }

    // output result
    for (int i = 0; i < config.classes_count; ++i) {
        int offset = config.ranking_size * i;

        for (int j = 0; j < config.ranking_size; ++j) {
            printf(
                "Class %d %d, DPS %.2f, "
                "STR %d, INT %d, ACC %d, AGI %d, DEF %d, STA %d\n",
                i + 1, j + 1, results[offset + j].dps,

                results[offset + j].build.char_points.primary_stats.stat_str,
                results[offset + j].build.char_points.primary_stats.stat_int,
                results[offset + j].build.char_points.primary_stats.stat_acc,
                results[offset + j].build.char_points.primary_stats.stat_agi,
                results[offset + j].build.char_points.primary_stats.stat_def,
                results[offset + j].build.char_points.primary_stats.stat_sta
            );
        }
    }

    clock_t end = clock();

    printf("Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // cleanup
    // we are not cleaning up pointers from the main since we are closing the app anyways

    return 0;
}