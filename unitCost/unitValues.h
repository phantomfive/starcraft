#ifndef UNIT_VALUES
#define UNIT_VALUES

/*****************************************************************************
 * Holds the values for various Starcraft 2 units.                           *
 *                                                                           *
 * Copyright 2013 A Thompson, Usable under the terms of the GPL 3 or greater *
 *****************************************************************************/

//Usually, with three workers you can get 114 gas per game minute
#define GAS_PER_GEYSER 114

//With 24 workers, you can get 816 minerals per base
//With 16 workers, you can get 660 minerals per base
#define MINERALS_PER_BASE       816
#define MINERALS_PER_SMALL_BASE 660

typedef struct unit_struct {
	char name[100];    //name of the unit
	int minerals;      //number of minerals it costs to build the thing
	int gas;           //amount of gas it costs to build the thing
	int time;          //time, in game seconds, it takes to build
} Unit;

Unit terranUnits[] = {
//name        ,mnls,  gas, time
{"SCV"        ,  50,    0,  17 },
{"Marine"     ,  50,    0,  25 }, 0};



#endif


