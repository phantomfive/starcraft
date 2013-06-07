/**************************************************************************
 * Calculates the number of units that can be built per minute.           *
 *                                                                        *
 * Copyright 2013 A Thompson, usable under the GPL 3.0 or greater.        *
 **************************************************************************/
#include <stdio.h>
#include <string.h>
#include "unitValues.h"

//In theory these can be changed by command line arguments
static BOOL shouldPrintTerranTable  = TRUE;
static BOOL shouldPrintProtossTable = TRUE;
static BOOL shouldPrintZergTable    = TRUE;

static void printUnitTableFlexible(const Unit *table, int gasPerMinute, 
                                   int mineralsPerMinute) {
	const Unit *u;

	for(u = &table[0];strlen(u->name)!=0;u++)  {

		//First calculate all the values we need
		double perMinuteIfGasLimiting = 0; //have to avoid division by zero
		double perMinuteIfMnsLimiting = 0; //have to avoid division by zero
		if(u->gas!=0)
			perMinuteIfGasLimiting = (double)gasPerMinute / (double)u->gas;
		if(u->minerals!=0)
			perMinuteIfMnsLimiting = (double)mineralsPerMinute/(double)u->minerals;
		
		BOOL mineralsAreTheLimitingFactor;
		if(perMinuteIfGasLimiting==0) {
			mineralsAreTheLimitingFactor = TRUE;
		}else if(perMinuteIfGasLimiting==0) {
			mineralsAreTheLimitingFactor = FALSE;
		}else {
			mineralsAreTheLimitingFactor = perMinuteIfGasLimiting >
		                                  perMinuteIfMnsLimiting;
		}


		//calculate more stuff
		int    gasLeftOver;
		int    mnsLeftOver;
		double unitsPerMinute;
		double buildingsRequired;
		if(mineralsAreTheLimitingFactor) {
			unitsPerMinute = perMinuteIfMnsLimiting;
			mnsLeftOver    = 0;
			gasLeftOver    = gasPerMinute - unitsPerMinute * u->gas;
		}
		else {
			unitsPerMinute = perMinuteIfGasLimiting;
			mnsLeftOver    = mineralsPerMinute - unitsPerMinute * u->minerals;
			gasLeftOver    = 0;
		}

		buildingsRequired = unitsPerMinute * ((double)u->time/60.0);

		//Now we've calculated it, print it out
		printf("| %-15s | per minute %5.2f | buildings required %5.2f |"\
		       " gas left over %3d | minerals left over %3d |\n",
		       u->name, unitsPerMinute, buildingsRequired, gasLeftOver,
				 mnsLeftOver);
	}
}

static void printUnitTable(const Unit *table) {
	
	printf("---->Table with single base saturated (24 workers):\n");
	printUnitTableFlexible(table, GAS_PER_GEYSER * 2, MINERALS_PER_BASE);

	printf("\n\n---->Table with single base semi-saturaed (16 workers):\n");
	printUnitTableFlexible(table, GAS_PER_GEYSER * 2, MINERALS_PER_SMALL_BASE);

}

static void printTerranTable() {
	printf("+--------+\n");
	printf("| TERRAN |\n");
	printf("+--------+\n");
	printUnitTable(terranHOTS);
}
static void printProtossTable() {
	printf("+---------+\n");
	printf("| PROTOSS |\n");
	printf("+---------+\n");
	printf(" -> Coming Soon <-\n");
}
static void printZergTable() {
	printf("+------+\n");
	printf("| ZERG |\n");
	printf("+------+\n");
	printf(" -> Coming Soon <-\n");
}


static void parseCommandLineArgs(int argc, char**argv) {
	//in practice we still don't do anything with command line arguments
}

const char * explanation =
"Calculates how many units can be created on a single base.\n"
"First calculates the number of that unit that can be created, then it\n"
"calculates how many buildings you'll need if you want to spend all your\n"
"money. Both these tables assume you have six workers mining gas\n";

int main(int argc, char **argv) {

	parseCommandLineArgs(argc, argv);
	
	printf("%s", explanation);

	if(shouldPrintTerranTable)  printTerranTable ();
	if(shouldPrintProtossTable) printProtossTable();
	if(shouldPrintZergTable)    printZergTable   ();

	return 0;
}

