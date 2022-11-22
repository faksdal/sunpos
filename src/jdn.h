/*
 *
 *	jdn.h
 *	created 16 Nov 2022 by jole
 *
 *	class jdn holds an instance of a julian day number calculated from the date provided to the constructor
 *	The class accepts dates from both Julian and Gregorian calendars
 *
 *	Constructor parameters:
 * 		jdnYear:	the year as an integer, i.e. 2022 or -1
 * 		jdnMonth:	the month as a short, 1 = January, 2 = February and so forth
 * 		jdnDay:		the day of the month
 *		jdnHour:	the hour of the day, 0-23, local time
 *		jdnMinute:	the minute of the hour 0-59, local time
 *		jdnSecond:	the second of the minute, 0-59, local time
 *
 *	Data members:
 *		jdnGregorianDate:	holds true if the date provided is Gregorian, e.g. after Oct. 15th 1582. Otherwise it holds false
 *		jdnValidDate:		upon the transition from Julian to Gregorian calendars, there are 10 dates in our history that doesn't exist
 *							these dates are 5th - 14th Oct. 1582
 *		jdnJulianDay:		lorem ipsum
 *		jdnJulianCentury:	lorem ipsum
 *		T:					lorem ipsum
 *		jdnMeeus:			lorem ipsum
 *
 *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 *
*/

#ifndef __jdn_h__
#define __jdn_h__

using namespace std;

#include <math.h>



class jdn {

	bool	jdnGregorianDate, jdnValidDate, jdnVerbose;
	short	jdnMonth, jdnDay, jdnHour, jdnMinute, jdnSecond, jdnTz;
	int		jdnYear;

	double	jdnJulianDay, jdnJulianCentury, jdnMeeus, T;

	void	jdnParseDate(void);
	void	jdnCalculateJdnMeeus1998(void);
	void	jdnCalculateJdn(void);


public:
	jdn(int year, short month, short day, short hour, short minute, short second, short tz, bool verbose);
	virtual ~jdn();

	// inline public functions to return class-data-member-values
	int		jdnGetJdnYear(void)				{ return jdnYear; }
	short	jdnGetJdnMonth(void)			{ return jdnMonth; }
	short	jdnGetJdnDay(void)				{ return jdnDay; }
	short	jdnGetJdnHour(void)				{ return jdnHour; }
	short	jdnGetJdnMinute(void)			{ return jdnMinute; }
	short	jdnGetJdnSecond(void)			{ return jdnSecond; }
	short	jdnGetJdnTz(void)				{ return jdnTz; }
	double	jdnGetJdnJulianDay(void)		{ return jdnJulianDay; }
	double	jdnGetJdnMeeus(void)			{ return jdnMeeus; }
	double	jdnGetT(void)					{ return T; }
	double	jdnGetJdnJulianCentury(void)	{ return jdnJulianCentury; }
};

#endif // __jdn_h__
