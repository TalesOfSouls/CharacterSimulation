#ifndef SIMULATE_CHAR_H
#define SIMULATE_CHAR_H

#include <stdlib.h>
#include "SimulationDefinitions.h"
#include "../GameEngine/stdlib/simd/SIMD_I32.h"
#include "../GameEngine/utils/Utils.h"

void mutate_char_build(CharacterBuild* build, float mutation_rate, int step = 8) {
    int temp;
    int stat_points = 100;

    float* rands;
    float* rands_f;

    if (step == 16) {
        rands = (float *) aligned_alloc(64, 68 * sizeof(float));
        rands_f = (float *) aligned_alloc(64, 68 * sizeof(float));
    } else if (step == 8) {
        rands = (float *) aligned_alloc(32, 68 * sizeof(float));
        rands_f = (float *) aligned_alloc(32, 68 * sizeof(float));
    } else if (step == 4) {
        rands = (float *) aligned_alloc(16, 68 * sizeof(float));
        rands_f = (float *) aligned_alloc(16, 68 * sizeof(float));
    } else {
        rands = (float *) malloc(68 * sizeof(float));
        rands_f = (float *) malloc(68 * sizeof(float));
    }

    for (int i = 0; i < 68; ++i) {
        rands[i] = (float) rand();
    }

    simd_div(rands, (float) RAND_MAX, rands_f, 68, step);

    build->char_points.primary_stats.stat_str = rands_f[0] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.primary_stats.stat_str) ? build->char_points.primary_stats.stat_str : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_int = rands_f[1] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.primary_stats.stat_int) ? build->char_points.primary_stats.stat_int : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_acc = rands_f[2] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.primary_stats.stat_acc) ? build->char_points.primary_stats.stat_acc : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_agi = rands_f[3] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.primary_stats.stat_agi) ? build->char_points.primary_stats.stat_agi : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_def = rands_f[4] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.primary_stats.stat_def) ? build->char_points.primary_stats.stat_def : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_sta = rands_f[5] <= mutation_rate
        ? (uint16) stat_points
        : (uint16) (temp = (stat_points >= build->char_points.primary_stats.stat_sta) ? build->char_points.primary_stats.stat_sta : stat_points);

    stat_points = 100;

    build->char_points.secondary_stats.dmg_piercing = rands_f[6] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dmg_piercing) ? build->char_points.secondary_stats.dmg_piercing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_reflection = rands_f[7] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dmg_reflection) ? build->char_points.secondary_stats.dmg_reflection : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_reflection_chance = rands_f[8] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dmg_reflection_chance) ? build->char_points.secondary_stats.dmg_reflection_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_crit = rands_f[9] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dmg_crit) ? build->char_points.secondary_stats.dmg_crit : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_crit_chance = rands_f[10] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dmg_crit_chance) ? build->char_points.secondary_stats.dmg_crit_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health = rands_f[11] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health) ? build->char_points.secondary_stats.health : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_on_dmg_dealt = rands_f[12] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_on_dmg_dealt) ? build->char_points.secondary_stats.health_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_on_dmg_taken = rands_f[13] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_on_dmg_taken) ? build->char_points.secondary_stats.health_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen = rands_f[14] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_regen) ? build->char_points.secondary_stats.health_regen : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen_rel = rands_f[15] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_regen_rel) ? build->char_points.secondary_stats.health_regen_rel : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen_on_dmg_dealt = rands_f[16] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_regen_on_dmg_dealt) ? build->char_points.secondary_stats.health_regen_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen_on_dmg_taken = rands_f[17] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_regen_on_dmg_taken) ? build->char_points.secondary_stats.health_regen_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource = rands_f[18] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource) ? build->char_points.secondary_stats.resource : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_on_dmg_dealt = rands_f[19] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_on_dmg_dealt) ? build->char_points.secondary_stats.resource_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_on_dmg_taken = rands_f[20] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_on_dmg_taken) ? build->char_points.secondary_stats.resource_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen = rands_f[21] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen) ? build->char_points.secondary_stats.resource_regen : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen_rel = rands_f[22] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen_rel) ? build->char_points.secondary_stats.resource_regen_rel : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen_on_dmg_dealt = rands_f[23] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen_on_dmg_dealt) ? build->char_points.secondary_stats.resource_regen_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen_on_dmg_taken = rands_f[24] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen_on_dmg_taken) ? build->char_points.secondary_stats.resource_regen_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_loss = rands_f[25] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_loss) ? build->char_points.secondary_stats.resource_loss : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_loss_on_dmg_dealt = rands_f[26] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_loss_on_dmg_dealt) ? build->char_points.secondary_stats.resource_loss_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_loss_on_dmg_taken = rands_f[27] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_loss_on_dmg_taken) ? build->char_points.secondary_stats.resource_loss_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dodge_chance = rands_f[28] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dodge_chance) ? build->char_points.secondary_stats.dodge_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.cc_protection = rands_f[29] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.cc_protection) ? build->char_points.secondary_stats.cc_protection : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.miss_chance = rands_f[30] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.miss_chance) ? build->char_points.secondary_stats.miss_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_walk1 = rands_f[31] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.speed_walk1) ? build->char_points.secondary_stats.speed_walk1 : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_swim1 = rands_f[32] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.speed_swim1) ? build->char_points.secondary_stats.speed_swim1 : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_fly1 = rands_f[33] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.speed_fly1) ? build->char_points.secondary_stats.speed_fly1 : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_cast = rands_f[34] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.speed_cast) ? build->char_points.secondary_stats.speed_cast : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_attack = rands_f[35] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.speed_attack) ? build->char_points.secondary_stats.speed_attack : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.pickup_range = rands_f[36] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.pickup_range) ? build->char_points.secondary_stats.pickup_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shield = rands_f[37] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.shield) ? build->char_points.secondary_stats.shield : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.aoe_scale = rands_f[38] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.aoe_scale) ? build->char_points.secondary_stats.aoe_scale : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_cost = rands_f[39] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_cost) ? build->char_points.secondary_stats.resource_cost : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_cost = rands_f[40] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.health_cost) ? build->char_points.secondary_stats.health_cost : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.attack_range = rands_f[41] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.attack_range) ? build->char_points.secondary_stats.attack_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.melee_range = rands_f[42] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.melee_range) ? build->char_points.secondary_stats.melee_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.projectile_speed = rands_f[43] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.projectile_speed) ? build->char_points.secondary_stats.projectile_speed : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.projectile_count = rands_f[44] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.projectile_count) ? build->char_points.secondary_stats.projectile_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_probability = rands_f[45] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.shatter_probability) ? build->char_points.secondary_stats.shatter_probability : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_range = rands_f[46] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.shatter_range) ? build->char_points.secondary_stats.shatter_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_dmg = rands_f[47] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.shatter_dmg) ? build->char_points.secondary_stats.shatter_dmg : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_count = rands_f[48] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.shatter_count) ? build->char_points.secondary_stats.shatter_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.passthrough_damage = rands_f[49] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.passthrough_damage) ? build->char_points.secondary_stats.passthrough_damage : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.passthrough_count = rands_f[50] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.passthrough_count) ? build->char_points.secondary_stats.passthrough_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dot_duration = rands_f[51] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dot_duration) ? build->char_points.secondary_stats.dot_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dot_count = rands_f[52] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.dot_count) ? build->char_points.secondary_stats.dot_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.bleeding_dot = rands_f[53] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.bleeding_dot) ? build->char_points.secondary_stats.bleeding_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.poison_dot = rands_f[54] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.poison_dot) ? build->char_points.secondary_stats.poison_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.burn_dot = rands_f[55] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.burn_dot) ? build->char_points.secondary_stats.burn_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.ice_dot = rands_f[56] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.ice_dot) ? build->char_points.secondary_stats.ice_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_drain = rands_f[57] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.resource_drain) ? build->char_points.secondary_stats.resource_drain : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_dot = rands_f[58] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.shatter_dot) ? build->char_points.secondary_stats.shatter_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.minion_duration = rands_f[59] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.minion_duration) ? build->char_points.secondary_stats.minion_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.minion_count = rands_f[60] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.minion_count) ? build->char_points.secondary_stats.minion_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_spreading_probability = rands_f[61] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.effect_spreading_probability) ? build->char_points.secondary_stats.effect_spreading_probability : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_spreading_radius = rands_f[62] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.effect_spreading_radius) ? build->char_points.secondary_stats.effect_spreading_radius : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_spreading_max_count = rands_f[63] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.effect_spreading_max_count) ? build->char_points.secondary_stats.effect_spreading_max_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_duration = rands_f[64] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.effect_duration) ? build->char_points.secondary_stats.effect_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.aura_range = rands_f[65] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.aura_range) ? build->char_points.secondary_stats.aura_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.cast_duration = rands_f[66] <= mutation_rate
        ? (uint16) (temp = (fast_rand1() % (stat_points + 1)))
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.cast_duration) ? build->char_points.secondary_stats.cast_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.aggro_range = rands_f[67] <= mutation_rate
        ? (uint16) stat_points
        : (uint16) (temp = (stat_points >= build->char_points.secondary_stats.aggro_range) ? build->char_points.secondary_stats.aggro_range : stat_points);

    if (step > 1) {
        aligned_free(rands);
        aligned_free(rands_f);
    } else {
        free(rands);
        free(rands_f);
    }
}

#endif;