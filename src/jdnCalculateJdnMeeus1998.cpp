#include "jdn.h"

#include <stdio.h>

// The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998

void jdn::jdnCalculateJdnMeeus1998(void)
{
	int		A, B, M, Y;


	//printf("Year: %d\n", jdnYear);
	//printf("Month: %d\n", jdnMonth);
	//printf("Day: %d\n", jdnDay);
	//printf("a: %f, m: %f, y: %f\n", a, m, y);

	M = jdnMonth;
	Y = jdnYear;

	if((M == 1) || (M == 2) ){
		//printf("calculate month and year...\n");
		M += 12;
		Y--;
	}

	// different algorithms based on which calendar used, Gregorian or Julian
	if(!jdnGregorianDate){
		if(jdnVerbose)
			printf("Perform Meeus calculations based on Julian date...\n");

		A	=	floor(jdnYear/100);
		B	=	0;


	}
	else if(jdnGregorianDate){
			if(jdnVerbose)
				printf("Perform Meeus calculations based on Gregorian date...\n");

			// The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998
			//A	=	floor(jdnYear/100);
			//int B	=	2 - A + floor(A/4);
			B	=	2 - (floor(jdnYear/100)) + floor((floor(jdnYear/100))/4);


	}

	jdnMeeus =		floor(365.25 * (Y + 4716))
				+	floor(30.6001 * (M + 1))
				+	jdnDay + B - 1524.5;


	// Calculate the fraction of the day
	jdnMeeus += (((jdnHour-jdnTz) + (jdnMinute/60.) + (jdnSecond/3600.) )/24.);

	//printf("JDN at noon, before calculating time offset %f\n", jdnJulianDay);

	// take off half-a-day so that we start at midnight
	//jdnJulianDay -= 0.5;

	//printf("JDN at noon, before calculating time offset %f\n", jdnJulianDay);


	//printf("JDN at noon, after calculating time offset %f\n", jdnJulianDay);

	// calculating Julian Century
	T = jdnJulianCentury = ((jdnMeeus - 2451545.) / 36525.);

	return;
}
