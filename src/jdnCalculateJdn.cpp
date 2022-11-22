#include "jdn.h"

#include <stdio.h>


void jdn::jdnCalculateJdn(void)
{
	float	a, m, y;

	// pre-calculations used in both algorithms
	a	= floor(((14 - jdnMonth) / 12));
	m	= jdnMonth - 3 + floor(12 * a);
	y	= jdnYear + 4800 - a;

	/*
	printf("Year: %d\n", jdnYear);
	printf("Month: %d\n", jdnMonth);
	printf("Day: %d\n", jdnDay);
	printf("a: %f, m: %f, y: %f\n", a, m, y);
	*/

	// different algorithms based on which calendar used, Gregorian or Julian
	if(!jdnGregorianDate){
		if(jdnVerbose)
			printf("Perform calculations based on Julian date...\n");

		jdnJulianDay = jdnDay + floor((153 * m + 2) / 5) + floor(365 * y) + floor(y / 4) - 32083;

		// The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998

	}

	else if(jdnGregorianDate){
			if(jdnVerbose)
				printf("Perform calculations based on Gregorian date...\n");


			jdnJulianDay =	jdnDay
							+ floor(((153 * m) + 2) / 5)
							+ (365 * y)
							+ floor(y / 4)
							- floor(y / 100)
							+ floor(y / 400)
							- 32045;


	}


	//printf("JDN at noon, before calculating time offset %f\n", jdnJulianDay);

	// take off half-a-day so that we start at midnight
	jdnJulianDay -= 0.5;

	//printf("JDN at noon, before calculating time offset %f\n", jdnJulianDay);
	jdnJulianDay += ((jdnHour + (jdnMinute/60.) + (jdnSecond/3600.) )/24.);

	if(jdnVerbose)
		printf("JDN at noon, after calculating time offset %f\n", jdnJulianDay);

	return;
}
