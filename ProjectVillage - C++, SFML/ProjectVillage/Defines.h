#pragma once

// Windows Size

#define WIDTH 1200
#define HEIGHT 800


// Fonts

#define defaultFont 0


// Buildings

#define TOWNHALL 0
#define LUMBERMILL 1
#define BRICKYARD 2
#define MINE 3
#define FARM 4
#define BARRACK 5
#define STABLE 6
#define SMITHY 7
#define HOUSES 8
#define WALLS 9


#define BuildingsCount 10

// Resources

#define WOOD 0
#define IRON 1
#define CLAY 2
#define FOOD 3
#define PEOPLE 4
#define MAXPEOPLE 5
#define TIME 6

// Units

#define PIKEMAN 0
#define SWORDSMAN 1
#define AXEMAN 2
#define ARCHERS 3
#define LIGHTCAVALRYMAN 4
#define HEAVYCAVALRYMAN 5

// UpdateCodes

#define RESOURCES_UPDATE 0
#define PEOPLE_COUNT_UPDATE 1
#define PEOPLE_MAX_COUNT_UPDATE 2
#define BUILDINGS_UPDATE 3
#define TIME_UPDATE 4
#define UNITS_INPUT_AMOUNT_UPDATE 5
#define UNITS_UPDATE 6
#define FOOD_UPDATE 7
#define RANDOM_EVENT_UPDATE 8
#define ENDGAME_UPDATE 9

// Others

#define FOOD_TO_ONE_MAN 2
#define MAX_TIER_EVENT 4

#define TIER_0 0
#define TIER_1 1
#define TIER_2 2
#define TIER_3 3

// Event Vector

#define EV_WOOD 0
#define EV_IRON 1
#define EV_CLAY 2
#define EV_FOOD 3
#define EV_RECRUIT_PIKEMAN 4
#define EV_RECRUIT_SWORDSMAN 5
#define EV_RECRUIT_AXEMAN 6
#define EV_RECRUIT_ARCHERS 7
#define EV_RECRUIT_LIGHTCAVALRYMAN 8
#define EV_RECRUIT_HEAVYCAVALRYMAN 9
#define EV_ENEMY_PIKEMAN 10
#define EV_ENEMY_SWORDSMAN 11
#define EV_ENEMY_AXEMAN 12
#define EV_ENEMY_ARCHERS 13
#define EV_ENEMY_LIGHTCAVALRYMAN 14
#define EV_ENEMY_HEAVYCAVALRYMAN 15
#define EV_BATTLE 16
#define EV_ENDGAME 17

// Random Events ID

#define EV_ID_ABUDANCE 0
#define EV_ID_BARBARIANATTACK 1
#define EV_ID_DESERTION 2
#define EV_ID_IRONDEPOSIT 3
#define EV_ID_LOCUST 4
#define EV_ID_MARRAUDERATTACK 5
#define EV_ID_THIEVES 6
#define EV_ID_BLOCKOFCLAY 7
#define EV_ID_BIGTREE 8
#define EV_ID_NOMADSATTACK 9
#define EV_ID_RECRUIT 10