/*
 * jdn.cpp
 *
 *	Created on: 16 Oct 2022
 *	Author: jole
 *      
 *	Class julianDay calculates the Julian Day Number for the given date and time.
 *
 *	This work is largely based on the work of Jean Meeus and his writing in the
 *	publication Astronomical Algorithms ISBN 0-943396-61-1
 *	It can be found here https://isbnsearch.org/isbn/0943396611
 *	
 *	The work also includes resources I found here:
 *		- https://www.ladybug.tools/ladybug-web/solar-calculator-noaa/noaa-sandbox-r2.html
 *		- https://gml.noaa.gov/grad/solcalc/main.js
 *		- https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation
 *		  
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */


#include "jdn.h"

//#include <math.h>
//#include <stdio.h>
//#include <string>
#include <iostream>

using namespace std;



jdn::jdn(int year, short month, short day, short hour, short minute, short second, short tz, bool verbose)
{
	jdnYear			= year;
	jdnMonth		= month;
	jdnDay			= day;

	jdnHour		= hour;
	jdnMinute	= minute;
	jdnSecond	= second;

	jdnTz		= tz;

	// initialize to NIL
	jdnJulianDay		= 0.;
	jdnJulianCentury	= 0.;
	jdnMeeus			= 0.;

	jdnVerbose = verbose;

	jdnParseDate();
	
	//printf("\nJulian day params: date: %d/%02d/%02d, local time: %02d:%02d:%02d timezone: %d DST: %d\n\n", jdYear, jdMonth, jdDay, jdHour, jdMinutes, jdSeconds, jdTZ, jdDST);

	//jdnCalculateJdn();
	jdnCalculateJdnMeeus1998();
	/*
	
	*/
	

	//printf("jdJulianDay - 2451545.: %f\n", jdnJulianDay - 2451545.);
	//printf("jc: %f\n", jdnJulianCentury);


}



jdn::~jdn() {
	// TODO Auto-generated destructor stub
}



/*JulianDay::JulianDay(const JulianDay &other) {
	// TODO Auto-generated constructor stub

}
*/
