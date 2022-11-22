/*
 * sunpos.cpp
 *
 *  Created on: 29 May 2020
 *      Author: jole
 *
 *	This work is largely based on the work of Jean Meeus and his writing in the
 *	publication Astronomical Algorithms ISBN 0-943396-61-1
 *	It can be found here https://isbnsearch.org/isbn/0943396611
 *
  *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

#include "sunpos.h"



sunpos::sunpos(int _year, short _month, short _day, short _hour, short _minute, short _second, bool _verbose, int _tz, double _lat, double _lon, int _dst):
		   jdn(_year, _month, _day, _hour, _minute, _second, _tz, _verbose)
{
	spTz		= _tz;
	spDst		= _dst;
	spVerbose	= _verbose;

	spLat	= _lat;
	spLon	= _lon;
	
	
	/*
	 *	The Suns geometric mean longitude...
	 */
	spGeomMeanLongSun	= fmod(280.46646 + jdnGetJdnJulianCentury() * (36000.76983 + jdnGetJdnJulianCentury() * 0.0003032), 360.);


	spGeomMeanAnomSun	= 357.52911 + jdnGetJdnJulianCentury()*(35999.05029 - 0.0001537 * jdnGetJdnJulianCentury());

	spEccentEarthOrbit	= 0.016708634 - jdnGetJdnJulianCentury() * (0.000042037 + 0.0000001267 * jdnGetJdnJulianCentury());
	spSunEqOfCtr		= sin(RADIANS(spGeomMeanAnomSun)) *
							  (1.914602 - jdnGetJdnJulianCentury() * (0.004817 + 0.000014 * jdnGetJdnJulianCentury())) +
							  sin(RADIANS(2. * spGeomMeanAnomSun)) *
							  (0.019993-0.000101 * jdnGetJdnJulianCentury()) +
							  sin(RADIANS(3. * spGeomMeanAnomSun)) *
							  0.000289;
	spSunTrueLong		= spGeomMeanLongSun + spSunEqOfCtr;

	spSunTrueAnom		= spGeomMeanAnomSun + spSunEqOfCtr;
	spSunRadVector		= (1.000001018 * (1. - spEccentEarthOrbit * spEccentEarthOrbit)) /
						  (1. + spEccentEarthOrbit * cos(RADIANS(spSunTrueAnom)));
	/*
	sunAppLong		= sunTrueLong - 0.00569 -
	                          0.00478 *
	                          sin(RADIANS(125.04 - 1934.136 * jc));
	meanObliqEcliptic	= 23 +
	                          (26 +
	                          ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;
	obliqCorr			= meanObliqEcliptic +
	                          0.00256 * cos(RADIANS(125.04 - 1934.136 * jc));
	sunRtAscen		= DEGREES(atan2(cos(RADIANS(obliqCorr)) * sin(RADIANS(sunAppLong)),
			                                cos(RADIANS(sunAppLong))));
	sunDeclin			= DEGREES(asin(sin(RADIANS(obliqCorr)) *
	                                  sin(RADIANS(sunAppLong))));
	varY				= tan(RADIANS(obliqCorr/2.)) *
	                          tan(RADIANS(obliqCorr/2.));
	eqOfTime			= 4 * DEGREES(varY *
	                                      sin(2 * RADIANS(geomMeanLongSun)) -
	                                      2 * eccentEarthOrbit *
	                                      sin(RADIANS(geomMeanAnomSun)) +
	                                      4 * eccentEarthOrbit * varY *
	                                      sin(RADIANS(geomMeanAnomSun)) *
	                                      cos(2 * RADIANS(geomMeanLongSun)) -
	                                      0.5 * varY	 * varY *
	                                      sin(4 * RADIANS(geomMeanLongSun)) -
	                                      1.25 * eccentEarthOrbit * eccentEarthOrbit *
	                                      sin(2 * RADIANS(geomMeanAnomSun)));


	this->haSunrise			= DEGREES(acos(cos(RADIANS(90.833)) /
	                                      (cos(RADIANS(this->lat)) *
	                                       cos(RADIANS(this->sunDeclin))) -
	                                       tan(RADIANS(this->lat)) *
	                                       tan(RADIANS(this->sunDeclin))));
	if(isnan(this->haSunrise))
		this->haSunrise = -1.;

	this->localSolarNoon	= (720 -
	                           4 * this->lon -
							   this->eqOfTime + this->tz * 60) /
	                           1440;
	this->localSunRise		= this->localSolarNoon - this->haSunrise *4 / 1440;
	//printf("haSunrise from sp.cpp: %f\n", this->haSunrise);
	this->localSunSet		= this->localSolarNoon + this->haSunrise * 4 / 1440;

	//std::cout << "geomMeanLongSun (degrees): " << this->getgeomMeanLongSun() << "\n";
	//std::cout << "geomMeanAnomSun (degrees): " << this->getgeomMeanAnomSun() << "\n";
	 *
	 */

	FLOATWIDTH		= 25;
	FLOATPRECISION	= 15;
	return;
}

sunpos::~sunpos()
{
	//delete Jd;
	return;
}



/*
char* SolarPhysics::timeStringFromDecimal(double time)
{
	char* retVal	= new char[16];
	
	if(!retVal)
		return NULL;

	time *= 24;

	int hour		= floor(time);
	int minutes		= floor((time - hour) * 60);
	int seconds		= floor((((time - hour) * 60) - minutes) * 60);

	sprintf(retVal, "%0d:%0d:%0d", hour, minutes, seconds);

	return retVal;
}
*/
