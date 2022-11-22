/*
 * sunpos.h
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *  Class sunpos builds on class jdn, and calculates the suns position based on the Julian Day Number from
 *  the jdn class.
 *
 *  Constructor parameters, inherited from class jdn:
 * 		jdnYear:	the year as an integer, i.e. 2022 or -1
 * 		jdnMonth:	the month as a short, 1 = January, 2 = February and so forth
 * 		jdnDay:		the day of the month
 *		jdnHour:	the hour of the day, 0-23, local time
 *		jdnMinute:	the minute of the hour 0-59, local time
 *		jdnSecond:	the second of the minute, 0-59, local time
 *
 *	Constructor parameters, native:
 *		tz:			timezone
 *  	dst:		daylight savings time, minutes (e.g. 0 or 60)
 *		lat:		the latitude we want to calculate for, given as decimal degrees, dd.ddddd°
 *		lon:		the longitude we want to calculate, given as decimal degrees, dd.ddddd°
 *
 *
 *	Data members:
 *  	geomMeanLongSun:
 *		geomMeanAnomSun:
 *		eccentEarthOrbit:
 *		sunEqOfCtr:
 *		sunTrueLong:
 *		sunTrueAnom:
 *		sunRadVector:
 *		sunAppLong:
 *		meanObliqEcliptic:
 *		obliqCorr:
 *		sunRtAscen:
 *		sunDeclin:
 *		varY:
 *		eqOfTime:
 *		haSunrise:
 *		localSolarNoon:
 *		localSunRise:
 *		localSunSet:
 *
 *
 *
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

#ifndef __sunpos_h__
#define __sunpos_h__

using namespace std;

#include "jdn.h"
#include <iomanip>
#include <iostream>



class sunpos : public jdn {

	int			spTz, spDst, FLOATWIDTH, FLOATPRECISION;
	bool		spVerbose;

	double		spGeomMeanLongSun,
				spGeomMeanAnomSun,
				spEccentEarthOrbit,
				spSunEqOfCtr,
				spSunTrueLong,
				spSunTrueAnom,
				spSunRadVector,
				spSunAppLong,
				spMeanObliqEcliptic,
				spObliqCorr,
				spSunRtAscen,
				spSunDeclin,
				spVarY,
				spEqOfTime,
				spHaSunrise,
				spLocalSolarNoon,
				spLocalSunRise,
				spLocalSunSet,
				spLat,
				spLon;


	//
	//	Private, inline functions to calculate back and forth between radians and degrees
	//
	double		RADIANS(double degrees) {return (degrees * M_PI / 180);}
	double		DEGREES(double radians) {return (radians * 180 / M_PI);}

public:
	sunpos(int _year, short _month, short _day, short _hour, short _minute, short _second, bool _verbose, int _tz, double _lat, double _lon, int _dst);
	virtual ~sunpos();

	double	spGetGeomMeanLongSun(void)		{ return spGeomMeanLongSun; }
	double	spGetGeomMeanAnomSun(void)		{ return spGeomMeanAnomSun; }
	double	spGetEccentEarthOrbit(void)		{ return spEccentEarthOrbit; }
	double	spGetSunEqOfCtr(void)			{ return spSunEqOfCtr; }

	double	spGetspLat(void)				{ return spLat; }
	double	spGetspLon(void)				{ return spLon; }
	double	spGetSunTrueLong(void)			{ return spSunTrueLong; }

	double	spGetSunTrueAnom(void)			{ return spSunTrueAnom; }
	double	spGetSunRadVector(void)			{ return spSunRadVector; }
	double	spGetSunAppLong(void)			{ return spSunAppLong; }
	double	spGetMeanObliqEcliptic(void)	{ return spMeanObliqEcliptic; }
	double	spGetObliqCorr(void)			{ return spObliqCorr; }
	double	spGetSunRtAscen(void)			{ return spSunRtAscen; }
	double	spGetSunDeclin(void)			{ return spSunDeclin; }
	double	spGetVarY(void)					{ return spVarY; }
	double	spGetEqOfTime(void)				{ return spEqOfTime; }
	double	spGetHaSunrise(void)			{ return spHaSunrise; }
	double	spgetLocalSolarNoon(void)		{ return spLocalSolarNoon; }
	double	spGetLocalSunRise(void)			{ return spLocalSunRise; }
	double	spGetLocalSunSet(void)			{ return spLocalSunSet; }


	// print to stdout (terminal)
	void	spPrintOutput(void);

	/*
	char*	timeStringFromDecimal(double time);

	
	int		gettz(void) { return tz;}

	char*	timeStringFromDecimal(double time);

	double	getJulianDay(void) {return jd;}
	double	getJulianCentury(void) {return jc;}







	*/

};

#endif /* __sunpos_h__ */
