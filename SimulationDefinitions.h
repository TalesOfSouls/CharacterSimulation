#ifndef SIMULATION_DEFINITIONS_H
#define SIMULATION_DEFINITIONS_H

#include "../cOMS/models/mob/MobStats.h"
#include "../cOMS/models/item/Equipment.h"
#include "../cOMS/models/mob/skill/Skill.h"

#define MAX_ITEMS 3

struct Settings {
    int classes[30];
    int classes_count;
    int char_level;
    int threads;
    int iterations;
    float mutation_rate;
    int ranking_size;
    int rand;
};

struct CharacterBuild {
    SMobStatsPoints char_points;
    SEquipmentStatsPoints equipment_points[15]; // @todo replace with more item infos (weapon type etc.... like real item)
    Skill skills[30];
};

struct BuildResult {
    CharacterBuild build;
    float dps;
    float health;
    float resource;
    float healing;
    float movement_speed;
};

struct ThreadData {
    int char_class_index;
    Settings* config;
    BuildResult* results;
};

#endif