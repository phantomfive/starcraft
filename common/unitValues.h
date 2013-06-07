#ifndef UNIT_VALUES
#define UNIT_VALUES

/*****************************************************************************
 * Holds the values for various Starcraft 2 units.                           *
 *                                                                           *
 * Copyright 2013 A Thompson, Usable under the terms of the GPL 3 or greater *
 *****************************************************************************/
#include <stdlib.h>
#include "common.h"

//Usually, with three workers you can get 114 gas per game minute
#define GAS_PER_GEYSER 114

//With 24 workers, you can get 816 minerals per base
//With 16 workers, you can get 660 minerals per base
#define MINERALS_PER_BASE       816
#define MINERALS_PER_SMALL_BASE 660

typedef enum race_e {
	TERRAN,
	ZERG,
	PROTOSS
} Race;

typedef struct unit_struct {
	char name[100];    //name of the unit
	int minerals;      //number of minerals it costs to build the thing
	int gas;           //amount of gas it costs to build the thing
	int time;          //time, in game seconds, it takes to build
} Unit;

Unit terranHOTS[] = {
//name        ,mnls,  gas, time
{"SCV"           ,  50,    0,  17 },
{"Marine"        ,  50,    0,  25 },
{"Marauder"      , 100,   25,  30 },
{"Reaper"        ,  50,   50,  40 },
{"Ghost"         , 200,  100,  40 },
{"Hellion"       , 100,    0,  30 },
{"Widow Mine"    ,  75,   25,  40 },
{"Siege Tank"    , 150,  125,  45 },
{"Viking"        , 150,   75,  42 },
{"Medivac"       , 100,  100,  42 },
{"Banshee"       , 150,  100,  60 },
{"Raven"         , 100,  200,  60 },
{"Thor"          , 300,  200,  60 },
{"Battlecruiser" , 400,  300,  90 },
{"",0,0,0}};


#endif


