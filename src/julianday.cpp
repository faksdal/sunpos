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

	// Format specifiers for output
	jd_FLOATWIDTH		= 25;
	jd_FLOATPRECISION	= 11;

	M = 0.00;


	//*************************************************************************
	// 1. Time; Calculate jd

	jd_calculateJulianDay();
	//*************************************************************************



	//*************************************************************************
	// 2. The Mean anomaly; Calculate and retreive the mean anomaly M
	ma = new meananomaly(jd_julianDayNumber, jd_j2000, jd_verbose);
	if(!ma){
		std::cerr << "Error allocating memory for M = new meananomaly(jd_julianDay_utc), exiting..." << std::endl;
		exit(-1);
	}

	// For the example at https://www.aa.quae.nl/en/reken/zonpositie.html
	// the date is 2004/04/1 at 12:00:00, and the calculated M = 87.1807
	M = ma->ma_getM("Earth");
	if(jd_verbose)
		std::cout << "Mean anomaly for Earth: " << M << std::endl;
	//*************************************************************************



	//*************************************************************************
	// 3. The equation of center
	eoc = new equationofcentre(M ,jd_verbose);
	if(!eoc){
		std::cerr << "Error allocating memory for eoc = new equationofcentre(M), exiting..." << std::endl;
		exit(-1);
	}
	C = eoc->eoc_getC("Earth");
	if(jd_verbose)
		std::cout << "Equation of centre for Earth: " << C << std::endl;

	v = M + C;

	//*************************************************************************



	//*************************************************************************
	// 4. The Perihelion and the Obliquity of the Ecliptic



	Π_Earth =	102.9373;
	ω_Earth =	23.4393;


	//*************************************************************************



	//*************************************************************************
	// 5. The Ecliptical Coordinates

	L = M + Π_Earth  + 180;
	λ = L + C;

	std::cout << "L = M + Π_Earth  + 180: " << fmod(λ, 360) << std::endl;


	//*************************************************************************



	//*************************************************************************
	// 6. The Equatorial coordinates



	//*************************************************************************



	//*************************************************************************
	// 7. The Observer
	//*************************************************************************



	//*************************************************************************
	// 8. Solar Transit
	//*************************************************************************



	//*************************************************************************
	// 9. Equation of Time
	//*************************************************************************



	//*************************************************************************
	// 10. Sunrise and Sunset
	//*************************************************************************

	jd_printToScreen();

	return;
}
