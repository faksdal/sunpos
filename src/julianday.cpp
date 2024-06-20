/*
 * julianday.cpp
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */


#include <cmath>
#include <math.h>

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

	class eclipticlongitudeandobliquity{

	private:

		struct Πε_table{
			std::string	planet;
			double		Π;
			double		ε;
		};

		Πε_table	Πε[NUMBEROFPLANETS] = {	"Mercury",	230.3265,	0.0351,
											"Venus",	73.7576,	2.6376,
											"Earth",	102.9373,	23.4393,
											"Mars",		71.0041,	25.1918,
											"Jupiter",	237.1015,	3.1189,
											"Saturn",	99.4587,	26.7285,
											"Uranus",	5.4634,	82.2298,
											"Neptune",	182.2100,	27.8477,
											"Pluto",	184.5484,	119.6075 };
	};



	Π_Earth =	102.9373;
	ε_Earth =	23.4393;


	//*************************************************************************



	//*************************************************************************
	// 5. The Ecliptical Coordinates

	L = M + Π_Earth  + 180;
	λ = L + C;

	std::cout << "L = M + Π_Earth  + 180: " << fmod(L, 360) << std::endl;
	std::cout << "             λ = L + C: " << fmod(λ, 360) << std::endl;


	//*************************************************************************



	//*************************************************************************
	// 6. The Equatorial coordinates

	// α right ascension
	// δ declination

	// arctan(x, y) == tan⁻¹(x/y)

	//α = atan2( cos(RADIANS(λ)), sin(RADIANS(λ)) * cos(RADIANS(L)));
	α = atan2( sin(RADIANS(λ)) * cos(RADIANS(ε_Earth)), cos(RADIANS(λ)));
	δ = asin( sin(RADIANS(λ)) *  sin(RADIANS(ε_Earth)));

	std::cout << "           α: " << DEGREES(α) << std::endl;
	std::cout << "           δ: " << DEGREES(δ) << std::endl;

	//*************************************************************************



	//*************************************************************************
	// 7. The Observer
	// φ, latitude phi
	// lw, longitude west
	// Θ, sideral time theta
	φ	= 52;
	lw	= (-5);
	Θ	= 280.1470 + (360.9856235 * (jd_julianDayNumber - jd_j2000)) - lw;
	//Θ	= 280.1470 + (360.9856235 * (jd_julianDayNumber - jd_j2000));
	std::cout << "          lw: " << lw << std::endl;
	std::cout << "           Θ: " << Θ << std::endl;
	std::cout << "           φ: " << φ << std::endl;
	std::cout << "Θ (fmod 360): " << fmod(Θ, 360) << std::endl;

	// double H;	// Hour angle
	// double A;	// Azimuth
	// double h;	// Altitude

	H = (fmod(Θ, 360) - DEGREES(α));

	double x = sin(RADIANS(H));
	double y = (cos(RADIANS(H)) * sin(RADIANS(φ))) - (tan((δ)) * cos(RADIANS(φ)));

	A = atan2(x, y);

	h = asin( sin(RADIANS(φ)) * sin(δ) + cos(RADIANS(φ)) * cos(δ) * cos(RADIANS(H)) );

	std::cout << "           H: " << H << std::endl;
	std::cout << "           A: " << A << std::endl;
	std::cout << "  DEGREES(A): " << DEGREES(A) << std::endl;
	std::cout << "           h: " << h << std::endl;
	std::cout << "  DEGREES(h): " << DEGREES(h) << std::endl << std::endl;


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
