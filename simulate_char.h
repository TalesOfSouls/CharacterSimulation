#ifndef SIMULATE_CHAR_H
#define SIMULATE_CHAR_H

#include <stdlib.h>
#include "SimulationDefinitions.h"

void mutate_char_build(CharacterBuild* build, float mutation_rate) {
    int temp;
    int stat_points = 100;

    // @todo use simd
    build->char_points.primary_stats.stat_str = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.primary_stats.stat_str) ? build->char_points.primary_stats.stat_str : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_int = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.primary_stats.stat_int) ? build->char_points.primary_stats.stat_int : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_acc = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.primary_stats.stat_acc) ? build->char_points.primary_stats.stat_acc : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_agi = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.primary_stats.stat_agi) ? build->char_points.primary_stats.stat_agi : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_def = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.primary_stats.stat_def) ? build->char_points.primary_stats.stat_def : stat_points);
    stat_points -= temp;
    build->char_points.primary_stats.stat_sta = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) stat_points
        : (byte) (temp = (stat_points >= build->char_points.primary_stats.stat_sta) ? build->char_points.primary_stats.stat_sta : stat_points);

    stat_points = 100;

    build->char_points.secondary_stats.dmg_pircing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_pircing) ? build->char_points.secondary_stats.dmg_pircing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_pircing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_pircing) ? build->char_points.secondary_stats.dmg_pircing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_slashing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_slashing) ? build->char_points.secondary_stats.dmg_slashing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_bludgeoning = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_bludgeoning) ? build->char_points.secondary_stats.dmg_bludgeoning : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_stabbing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_stabbing) ? build->char_points.secondary_stats.dmg_stabbing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_fire = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_fire) ? build->char_points.secondary_stats.dmg_fire : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_water = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_water) ? build->char_points.secondary_stats.dmg_water : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_wind = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_wind) ? build->char_points.secondary_stats.dmg_wind : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_earth = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_earth) ? build->char_points.secondary_stats.dmg_earth : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_poison = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_poison) ? build->char_points.secondary_stats.dmg_poison : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_lightning = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_lightning) ? build->char_points.secondary_stats.dmg_lightning : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_ice = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_ice) ? build->char_points.secondary_stats.dmg_ice : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_arcane = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_arcane) ? build->char_points.secondary_stats.dmg_arcane : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_corrupted = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_corrupted) ? build->char_points.secondary_stats.dmg_corrupted : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_holy = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_holy) ? build->char_points.secondary_stats.dmg_holy : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_reflection = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_reflection) ? build->char_points.secondary_stats.dmg_reflection : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_reflection_chance = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_reflection_chance) ? build->char_points.secondary_stats.dmg_reflection_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_crit = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_crit) ? build->char_points.secondary_stats.dmg_crit : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dmg_crit_chance = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dmg_crit_chance) ? build->char_points.secondary_stats.dmg_crit_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health) ? build->char_points.secondary_stats.health : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_on_dmg_dealt = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_on_dmg_dealt) ? build->char_points.secondary_stats.health_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_on_dmg_taken = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_on_dmg_taken) ? build->char_points.secondary_stats.health_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_regen) ? build->char_points.secondary_stats.health_regen : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen_rel = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_regen_rel) ? build->char_points.secondary_stats.health_regen_rel : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen_on_dmg_dealt = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_regen_on_dmg_dealt) ? build->char_points.secondary_stats.health_regen_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_regen_on_dmg_taken = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_regen_on_dmg_taken) ? build->char_points.secondary_stats.health_regen_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource) ? build->char_points.secondary_stats.resource : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_on_dmg_dealt = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_on_dmg_dealt) ? build->char_points.secondary_stats.resource_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_on_dmg_taken = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_on_dmg_taken) ? build->char_points.secondary_stats.resource_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen) ? build->char_points.secondary_stats.resource_regen : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen_rel = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen_rel) ? build->char_points.secondary_stats.resource_regen_rel : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen_on_dmg_dealt = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen_on_dmg_dealt) ? build->char_points.secondary_stats.resource_regen_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_regen_on_dmg_taken = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_regen_on_dmg_taken) ? build->char_points.secondary_stats.resource_regen_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_loss = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_loss) ? build->char_points.secondary_stats.resource_loss : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_loss_on_dmg_dealt = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_loss_on_dmg_dealt) ? build->char_points.secondary_stats.resource_loss_on_dmg_dealt : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_loss_on_dmg_taken = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_loss_on_dmg_taken) ? build->char_points.secondary_stats.resource_loss_on_dmg_taken : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_pircing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_pircing) ? build->char_points.secondary_stats.defense_pircing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_slashing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_slashing) ? build->char_points.secondary_stats.defense_slashing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_bludgeoning = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_bludgeoning) ? build->char_points.secondary_stats.defense_bludgeoning : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_stabbing = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_stabbing) ? build->char_points.secondary_stats.defense_stabbing : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_fire = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_fire) ? build->char_points.secondary_stats.defense_fire : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_water = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_water) ? build->char_points.secondary_stats.defense_water : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_ice = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_ice) ? build->char_points.secondary_stats.defense_ice : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_earth = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_earth) ? build->char_points.secondary_stats.defense_earth : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_wind = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_wind) ? build->char_points.secondary_stats.defense_wind : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_poison = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_poison) ? build->char_points.secondary_stats.defense_poison : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_lightning = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_lightning) ? build->char_points.secondary_stats.defense_lightning : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_holy = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_holy) ? build->char_points.secondary_stats.defense_holy : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_arcane = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_arcane) ? build->char_points.secondary_stats.defense_arcane : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.defense_corrupted = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.defense_corrupted) ? build->char_points.secondary_stats.defense_corrupted : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dodge_chance = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dodge_chance) ? build->char_points.secondary_stats.dodge_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.cc_protection = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.cc_protection) ? build->char_points.secondary_stats.cc_protection : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.miss_chance = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.miss_chance) ? build->char_points.secondary_stats.miss_chance : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_walk1 = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.speed_walk1) ? build->char_points.secondary_stats.speed_walk1 : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_swim1 = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.speed_swim1) ? build->char_points.secondary_stats.speed_swim1 : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_fly1 = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.speed_fly1) ? build->char_points.secondary_stats.speed_fly1 : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_cast = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.speed_cast) ? build->char_points.secondary_stats.speed_cast : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.speed_attack = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.speed_attack) ? build->char_points.secondary_stats.speed_attack : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.pickup_range = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.pickup_range) ? build->char_points.secondary_stats.pickup_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shield = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.shield) ? build->char_points.secondary_stats.shield : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.aoe_scale = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.aoe_scale) ? build->char_points.secondary_stats.aoe_scale : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_cost = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_cost) ? build->char_points.secondary_stats.resource_cost : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.health_cost = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.health_cost) ? build->char_points.secondary_stats.health_cost : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.attack_range = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.attack_range) ? build->char_points.secondary_stats.attack_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.melee_range = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.melee_range) ? build->char_points.secondary_stats.melee_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.projectile_speed = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.projectile_speed) ? build->char_points.secondary_stats.projectile_speed : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.projectile_count = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.projectile_count) ? build->char_points.secondary_stats.projectile_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_probability = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.shatter_probability) ? build->char_points.secondary_stats.shatter_probability : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_range = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.shatter_range) ? build->char_points.secondary_stats.shatter_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_dmg = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.shatter_dmg) ? build->char_points.secondary_stats.shatter_dmg : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_count = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.shatter_count) ? build->char_points.secondary_stats.shatter_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.passthrough_damage = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.passthrough_damage) ? build->char_points.secondary_stats.passthrough_damage : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.passthrough_count = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.passthrough_count) ? build->char_points.secondary_stats.passthrough_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dot_duration = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dot_duration) ? build->char_points.secondary_stats.dot_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.dot_count = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.dot_count) ? build->char_points.secondary_stats.dot_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.bleeding_dot = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.bleeding_dot) ? build->char_points.secondary_stats.bleeding_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.poison_dot = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.poison_dot) ? build->char_points.secondary_stats.poison_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.burn_dot = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.burn_dot) ? build->char_points.secondary_stats.burn_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.ice_dot = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.ice_dot) ? build->char_points.secondary_stats.ice_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.resource_drain = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.resource_drain) ? build->char_points.secondary_stats.resource_drain : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.shatter_dot = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.shatter_dot) ? build->char_points.secondary_stats.shatter_dot : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.minon_duration = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.minon_duration) ? build->char_points.secondary_stats.minon_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.minion_count = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.minion_count) ? build->char_points.secondary_stats.minion_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_spreading_probability = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.effect_spreading_probability) ? build->char_points.secondary_stats.effect_spreading_probability : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_spreading_radius = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.effect_spreading_radius) ? build->char_points.secondary_stats.effect_spreading_radius : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_spreading_max_count = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.effect_spreading_max_count) ? build->char_points.secondary_stats.effect_spreading_max_count : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.effect_duration = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.effect_duration) ? build->char_points.secondary_stats.effect_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.aura_range = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.aura_range) ? build->char_points.secondary_stats.aura_range : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.cast_duration = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) (temp = (rand() % (stat_points + 1)))
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.cast_duration) ? build->char_points.secondary_stats.cast_duration : stat_points);
    stat_points -= temp;
    build->char_points.secondary_stats.agro_range = ((float) rand() / RAND_MAX) <= mutation_rate
        ? (byte) stat_points
        : (byte) (temp = (stat_points >= build->char_points.secondary_stats.agro_range) ? build->char_points.secondary_stats.agro_range : stat_points);
}

#endif;