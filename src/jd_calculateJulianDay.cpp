/*
 * jd_calculateJulianDay.cpp
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */

#include <math.h>		// floor()
#include <iostream>		// std::cout
#include <iomanip>		// precision formatters


#include "julianday.h"



void julianday::jd_calculateJulianDay(void)
{
	int		A, B, M, Y;

	Y = ts_getYear();
	M = ts_getMonth();

	std::cout << "Y: " << Y << std::endl;
	std::cout << "M: " << M << std::endl;

	if((M == 1) || (M == 2) ){
		Y--;
		M += 12;
	}

	std::cout << "Y: " << Y << std::endl;
	std::cout << "M: " << M << std::endl;

	//	Different algorithms based on which calendar is used, Gregorian or Julian
	//
	if(!ts_getGregorianDate()){
		if(jd_verbose)
			std::cout	<< "Perform Meeus calculations based on Julian date " << (int)ts_getDay()
						<< "/" << ts_getMonth()
						<< "-" << ts_getYear() << std::endl;

		//A	=	floor(jdnYear/100);
		B	=	0;
	}
	else if(ts_getGregorianDate()){
		if(jd_verbose)
			std::cout	<< "Perform Meeus calculations based on Gregorian date " << (int)ts_getDay()
						<< "/" << ts_getMonth()
						<< "-" << ts_getYear() << std::endl;

		//	The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998.
		A	=	floor(Y/100);
		B	=	2 - A + floor(A/4);
		//B	=	2 - (floor(Y/100.)) + floor((floor(Y/100.))/4.);
		std::cout << "A: " << A << std::endl;
		std::cout << "B: " << B << std::endl;

	}

	//
	//	Calculate the jdn according to p.61 (7.1) in Jean Meeus Astronomical Algorithms
	//	Second Edition published in 1998.
	//
	//	We calculate first the value for JD at noon
	//std::cout << "jd_julianDay: " << jd_julianDay << std::endl;
	std::cout << "(short)ts_getDay(): " << (short)ts_getDay() << std::endl;
	jd_julianDay =		floor(365.25 * (Y + 4716.))
					+	floor(30.6001 * (M + 1.))
					+	(short)ts_getDay() + B - 1524;
	//std::cout << "jd_julianDay: " << jd_julianDay << std::endl;

	//	Then we add the fraction of the day
	//jd_julianDayFraction = jd_julianDay + ((ts_getHour() + (ts_getMinute()/60.) + (ts_getSecond()/3600.))/24.);
	jd_julianDate = jd_julianDay - .5 + ((ts_getHour() + (ts_getMinute()/60.) + (ts_getSecond()/3600.))/24.);

	// Calculate doy
	short K;
	ts_getLeap() ? K = 1 : K = 2;
	jd_doy = floor( ((275 * ts_getMonth())/9) ) - K * floor(((ts_getMonth() + 9)/(12))) + ts_getDay() - 30;
	// doy

	//if(jd_verbose){
		std::cout << std::fixed;
		std::cout << "                  Julian Day(whole): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDay << std::endl;
		std::cout << "              Julian Date(fraction): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDate << std::endl;
		std::cout << "                                doy: " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_doy << std::endl;
	//}

/*
	//
	// Calculate the fraction of the day
	//
	jdnJulianDay += (((jd_hour - jdnTz) + (jdnMinute / 60.) + (jdnSecond / 3600.) ) / 24.);

	//if(jdnVerbose)
		//cout	<< "      Julian Day Number (jdn): " << setw(30) << setprecision(15) << setfill(' ') << jdnGetJdnJulianDay() << endl;

	//
	// Calculating Julian Century according to p.163 in Jean Meeus Astronomical Algorithms Second Edition published in 1998.
	//
	jdnJulianCentury		= ((jdnJulianDay - jdnJ2000) / 36525.);
	jdnJulianCenturyNoon	= ((jdnJdnNoon - jdnJ2000) / 36525.);

	jdnJulianMillennia		= ((jdnJulianDay - jdnJ2000) / 365250.);
	jdnJulianMillenniaNoon	= ((jdnJdnNoon - jdnJ2000) / 365250.);

	*/

	return;
}
