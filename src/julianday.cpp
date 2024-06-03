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

	//
	//	This is a fixed value used to calculate Julian century.
	//	See Meeus, Jean Astronomical Algorithms second edition p.163 (25.1)
	//
	jd_j2000	= 2451545.0;

	jd_FLOATWIDTH		= 25;
	jd_FLOATPRECISION	= 7;

	jd_calculateJulianDay();

	M = new meananomaly(jd_julianDay_utc, jd_j2000, jd_verbose);
	if(!M){
		std::cerr << "Error allocating memory for M = new meananomaly(jd_julianDay_utc), exiting..." << std::endl;
		exit(-1);
	}

	M->ma_getM("Pluto");
	M->ma_getM("Mercury");

	return;
}
