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

	//std::cout << "Y: " << Y << std::endl;
	//std::cout << "M: " << M << std::endl;

	if((M == 1) || (M == 2) ){
		Y--;
		M += 12;
	}

	//std::cout << "Y: " << Y << std::endl;
	//std::cout << "M: " << M << std::endl;

	//	Different algorithms based on which calendar is used, Gregorian or Julian
	//
	if(!ts_getGregorianDate()){
		if(jd_verbose)
			std::cout	<< "Performs Meeus calculations based on " << ts_getCalendarTypeString() << " date " << (int)ts_getDay()
						<< "/" << ts_getMonth()
						<< "-" << ts_getYear() << std::endl;

		//A	=	floor(jdnYear/100);
		B	=	0;
	}
	else if(ts_getGregorianDate()){
		if(jd_verbose)
			std::cout	<< "Performs Meeus calculations based on " << ts_getCalendarTypeString() << " date " << (int)ts_getDay()
						<< "/" << ts_getMonth()
						<< "-" << ts_getYear() << std::endl;

		//	The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998.
		A	=	floor(Y/100);
		B	=	2 - A + floor(A/4);
		//B	=	2 - (floor(Y/100.)) + floor((floor(Y/100.))/4.);
		//std::cout << "A: " << A << std::endl;
		//std::cout << "B: " << B << std::endl;

	}

	//
	//	Calculate the jdn according to p.61 (7.1) in Jean Meeus Astronomical Algorithms
	//	Second Edition published in 1998.
	//
	//	We calculate first the value for JD at noon
	//std::cout << "jd_julianDay: " << jd_julianDay << std::endl;
	//std::cout << "(short)ts_getDay(): " << (short)ts_getDay() << std::endl;
	jd_julianDayNumber	=	floor(365.25 * (Y + 4716.))
						+	floor(30.6001 * (M + 1.))
						+	(short)ts_getDay() + B - 1524;
	//std::cout << "jd_julianDay: " << jd_julianDay << std::endl;

	//	Then we add the fraction of the day
	//jd_julianDayFraction = jd_julianDay + ((ts_getHour() + (ts_getMinute()/60.) + (ts_getSecond()/3600.))/24.);
	jd_julianDate = jd_julianDayNumber + ((ts_getHour() - jd_getTz() + (ts_getMinute()/60.) + (ts_getSecond()/3600.))/24.);

	// Calculate doy
	short K;
	ts_getLeap() ? K = 1 : K = 2;
	jd_doy = floor( ((275 * ts_getMonth())/9) ) - K * floor(((ts_getMonth() + 9)/(12))) + ts_getDay() - 30;
	// doy

	// Calculate day of week (dow) as shown in Meeus, p.65
	// remainder = dividend % divisor;
	jd_dow = ((long)(jd_julianDay_utc + 1.5) % 7);
	//std::cout << "dow: " << jd_dow << std::endl;
	// Calculate dow


	return;
}
