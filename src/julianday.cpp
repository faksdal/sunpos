/*
 * julianday.cpp
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */


#include "julianday.h"



julianday::julianday(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose) :
           timestamp(_year, _month, _day, _hour, _minute, _second, _verbose)
{
	jd_tz		= _tz;
	jd_verbose	= _verbose;
	std::cout << "jd_verbose: " << (int)jd_verbose << std::endl;

	//
	//	This is a fixed value used to calculate Julian century.
	//	See Meeus, Jean Astronomical Algorithms second edition p.163 (25.1)
	//
	jd_j2000	= 2451545.0;

	// Format specifiers for output
	jd_FLOATWIDTH		= 25;
	jd_FLOATPRECISION	= 7;

	M = 0.00;

	// Calculate jd
	std::cout << "jd_verbose: " << (int)jd_verbose << std::endl;
	jd_calculateJulianDay();
	//*************************************************************************
	std::cout << "jd_verbose: " << (int)jd_verbose << std::endl;

	// Calculate and retreive the mean anomaly M
	ma = new meananomaly(jd_julianDay_utc, jd_j2000, jd_verbose);
	if(!ma){
		std::cerr << "Error allocating memory for M = new meananomaly(jd_julianDay_utc), exiting..." << std::endl;
		exit(-1);
	}
	M = ma->ma_getM("Earth");
	//if(jd_verbose)
		std::cout << "Mean anomaly for Earth: " << M << std::endl;
	//*************************************************************************

	return;
}
