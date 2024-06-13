/*
 * julianday.h
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */
/*
https://www.aa.quae.nl/en/reken/juliaansedag.html

|-------|-----------------------------------|---------------|---------------|-----------------------|
|		|		Name						|	Kind		|	Begins		|		From JD			|
|-------|-----------------------------------|---------------|---------------|-----------------------|
|JD		|	Julian Date						|	Fractional	|	12:00 UTC	|						|
|-------|-----------------------------------|---------------|---------------|-----------------------|
|JDN	|	Julian Day Number				|	Whole		|	12:00 UTC	|	=	J/DL			|
|-------|-----------------------------------|---------------|---------------|-----------------------|
|CJD	|	Chronological Julian Date		|	Fractional	|	00:00 LT	|	=	D	+ 0.5 + TZ	|
|-------|-----------------------------------|---------------|---------------|-----------------------|
|CJDN	|	Chronological Julian Day Number	|	Whole		|	00:00 LT	|	=	/D	+ 0.5 + TZL	|
|-------|-----------------------------------|---------------|---------------|-----------------------|

*/

#ifndef INC_JULIANDAY_H_
#define INC_JULIANDAY_H_

#include <string>
#include <iostream>
#include <inttypes.h>

#include "timestamp.h"
#include "meananomaly.h"




class julianday : public timestamp{

private:

	std::string	dow_name[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	//	Precision formatters for terminal printing
	short			jd_FLOATWIDTH, jd_FLOATPRECISION;

	short			jd_tz;
	short			jd_dow;

	int				jd_doy;					// day number of the year, starting with #1 on 1st of January

	double			jd_julianDayNumber;		// the Julian Day Number (JDN) counts the number of whole days since
											// 12:00 UTC or 12:00 TAI on January 1st, −4712 on the Julian proleptic calendar.
											// You get the Julian Day Number if you round a Julian Date (JD) down to the nearest whole value.
											// https://www.aa.quae.nl/cgi-bin/glossary.cgi?l=en&o=Julian%20Day%20Number

	double			jd_julianDate;			// The Julian Date (JD) counts the number of days since 12:00 UTC or 12:00 TAI on January
											// 1st, −4712 on the Julian proleptic calendar. Don't confuse a Julian Date (which consists of
											// a single number) with a date on the Julian calendar (which consists of three parts:
											// a year, a month, and a day). Julian Dates can have fractional parts. JD 2451545.25 indicates
											// the instant of time that is 0.25 days (i.e., 6 hours) past 12:00 UTC or
											// 12:00 TAI on January 1st, 2000 on the Gregorian calendar, i.e., 18:00 UTC or 18:00 TAI.
											// https://www.aa.quae.nl/cgi-bin/glossary.cgi?l=en&o=Julian%20Date

	double			jd_julianDay_utc;
	double			jd_j2000;
	double			M;

	bool			jd_verbose;

	meananomaly		*ma;



	void	jd_calculateJulianDay(void);

	std::string	jd_getDaySuffix(void);

public:
	julianday(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose);

	/*************************************************************************/
	short jd_getTz(void)		{ return jd_tz; }

	double	jd_getJ2000(void)			{ return jd_j2000; }
	double	jd_getJulianDayNumber(void)	{ return jd_julianDayNumber; }
	double	jd_getJulianDate(void)		{ return jd_julianDate; }

	std::string	jd_getDOW(void)	{ return dow_name[long(jd_julianDay_utc + 1.5) % (7)]; }
	/*************************************************************************/

	void	jd_printToScreen(void);

};



#endif /* INC_JULIANDAY_H_ */





/*
	┌── c₁ ──────────┐
	j ───────────┐ ┌─ a₁ ─(2)─ a₂ ─┐        │
				 (1)               │        │
	m ─(−1)─ m₀ ─┘ └─ m₁ ─┐        │        │
	d ─(−1)─ d₀ ─────────(3)─ d₁ ─(4)─ d₂ ─(5)─ s ─(+J₀)─ J


*/





















