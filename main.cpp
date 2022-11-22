using namespace std;

#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>

#include "jdn.h"
#include "sunpos.h"
#include "parseOptarg.h"



int main(int argc, char *argv[])
{
	bool	verbose = true;
	int		year, month, day, hour, minute, second, timezone, dst;
	double	lat, lon;

	
	/*getopt variables*/
	int		c, optionIndex;
	//float	input = 0L, output;
	char	*shortOptions = (char*)"vjd";
		
	struct option	longOptions[] = {
					{"date",	required_argument,	NULL,	1},
					{"time",	required_argument,	NULL,	2},
					{"tz",		required_argument,	NULL,	3},
					{"lat",		required_argument,	NULL,	4},
					{"lon",		required_argument,	NULL,	5},
					{"dst",		required_argument,	NULL,	6},
					{"verbose",	no_argument,		NULL,	'v'},
					//{"jdn",		no_argument,		NULL,	'j'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};
	/*	End of getopt()-variables*/

	//	Initialize command line variables to some default values, should the user fail to provide...
	//	This is for development purpose only, not to enter production code
	year		= 2022;
	month		= 11;
	day			= 21;
	hour		= 1;
	minute		= 12;
	second		= 0;
	timezone	= 1;
	dst			= 0;
	lat			= 64.466;
	lon			= 11.495;
	
	// Set the locale so we get numbers printed with 1000's separator
	setlocale(LC_ALL, "");
	//printf("%'d", 1000000);


	/*getopt switch statement*/
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 1:		{
								year = atoi(optarg);
								parseOptarg(&optarg);
								month = atoi(optarg);
								parseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg
																								
								// print for debug purposes
								//printf("year: %d, month: %d, day %d\n", year, month, day);
								break;
							}
				case 2:		{
								hour = atoi(optarg);
								parseOptarg(&optarg);
								minute = atoi(optarg);
								parseOptarg(&optarg);
								second = atoi(optarg);
								// end of parsing optarg
																															
								// print for debug purposes
								//printf("hour: %d, minute: %d, second %d\n", hour, minute, second);
								break;
							}
				case 3:		{	
								timezone = atoi(optarg);
								
								// print for debug purposes
								//printf("timezone: %d\n", timezone);
								break;
							}
				case 4:		{
								lat = atof(optarg);
								
								// print for debug purposes
								//printf("latitude: %f\n", lat);
								break;
				}
				case 5:		{	
								lon = atof(optarg);
								
								// print for debug purposes
								//printf("longitude: %f\n", lon);
								break;
							}
				case 6:		{
								dst = atoi(optarg);
								//printf("dst(min): %d\n", dst);
								break;
							}
				case 'v':	{
								verbose = true;
								break;
							}
				default:	{
								printf("switch default\n");
								break;
							}
			}	//end of getopt switch statement
		}	// end of while-loop
	

	// allocate memory for a sunpos-instance
	sunpos *sp = new sunpos(year, month, day, hour, minute, second, verbose, timezone, lat, lon, dst);

	//	handle any error that might occur
	if(!sp){
		cout << "Allocation failed: " << "memory Error" << '\n';
	}

	if(verbose){
		sp->spPrintOutput();
	}
	return 1;
}	// main
