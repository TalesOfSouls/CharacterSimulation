#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../GameEngine/thread/Thread.h"

#if _WIN32
    #include "../GameEngine/platform/win32/UtilsWin32.h"
#else
    #include "../GameEngine/platform/linux/UtilsLinux.h"
#endif

#include "SimulationDefinitions.h"
#include "simulate_char.h"
#include "simulate_item.h"

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
    float agi_mult;
    float acc_mult;

    switch (cclass) {
        case 1: {
            str_mult = 1.2f;
            agi_mult = 0.8f;
            acc_mult = 1.1f;
        } break;
        case 2: {
            str_mult = 0.9f;
            agi_mult = 0.8f;
            acc_mult = 1.1f;
        } break;
        case 3: {
            str_mult = 1.0f;
            agi_mult = 1.3f;
            acc_mult = 1.1f;
        } break;
        case 4: {
            str_mult = 1.1f;
            agi_mult = 1.5f;
            acc_mult = 0.9f;
        } break;
        case 5: {
            str_mult = 1.3f;
            agi_mult = 0.9f;
            acc_mult = 1.1f;
        } break;
        case 6: {
            str_mult = 1.4f;
            agi_mult = 1.0f;
            acc_mult = 1.1f;
        } break;
        case 7: {
            str_mult = 1.2f;
            agi_mult = 1.1f;
            acc_mult = 0.8f;
        } break;
        case 8: {
            str_mult = 1.1f;
            agi_mult = 1.12f;
            acc_mult = 0.9f;
        } break;
        default: {
            str_mult = 1.5f;
            agi_mult = 1.5f;
            acc_mult = 1.5f;
        }
    }

    return build->char_points.primary_stats.stat_str * str_mult
        + build->char_points.primary_stats.stat_agi * agi_mult
        + build->char_points.primary_stats.stat_acc * acc_mult;
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

#ifdef _WIN32
static DWORD WINAPI thread_func(void *arg)
#else
void* thread_func(void* arg)
#endif
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

    CharacterBuild new_build;

    for (int i = 0; i < thr_data->config->iterations; i++) {
        for (int j = 0; j < thr_data->config->ranking_size; ++j) {
            new_build = results[j].build;
            memcpy(&new_build, &results[j].build, sizeof(CharacterBuild));

            // perform mutation
            mutate_char_build(&new_build, (float) thr_data->config->mutation_rate);
            mutate_items_build(&new_build, (float) thr_data->config->mutation_rate);

            // perform calculations
            // handle dps
            float new_dps = calculate_dps(thr_data->config->classes[thr_data->char_class_index], &new_build);
            if (new_dps > worst_dps) {
                int c;
                for (c = thr_data->config->ranking_size - 1; (c > 0 && results[c - 1].dps < new_dps); --c) {
                    if (c < thr_data->config->ranking_size - 1) {
                        results[c] = results[c - 1];
                    }
                }

                results[c].build = new_build;
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

    pthread_exit(NULL);
}

int main() {
    // load settings
    Settings config;
    parse_config_file("settings.cfg", &config);
    srand(config.rand);

    // prepare data
    BuildResult* results = (BuildResult *) calloc(config.classes_count * config.ranking_size, sizeof(BuildResult));

    printf("\nBuild Count: %d\n", config.classes_count * config.ranking_size * config.iterations);
    printf("Cache Size: %ld\n\n", (int) (config.classes_count * config.ranking_size * sizeof(BuildResult)));

    // @todo first simulate the creation of N enemy mobs to fight against

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
                "Class %d %d. DPS %.2f "
                "STR %d INT %d ACC %d AGI %d DEF %d STA %d\n",
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

    // cleanup
    // we are not cleaning up pointers from the main since we are closing the app anyways

    return 0;
}