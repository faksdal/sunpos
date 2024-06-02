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




class julianday : public timestamp{

private:

	std::string	dow_name[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	//	Precision formatters for terminal printing
	short			jd_FLOATWIDTH, jd_FLOATPRECISION;

	short			jd_tz;
	short			jd_dow;

	int				jd_doy;
	//uint32_t		jd_julianDay;
	double			jd_julianDay_utc;

	bool			jd_verbose;

	double			jd_julianDate;



	void	jd_calculateJulianDay(void);

	std::string	jd_getDaySuffix(void);

public:
	julianday(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose);

	short jd_getTz(void) { return jd_tz; }
	std::string	jd_getDOW(void)	{ return dow_name[long(jd_julianDay_utc + 1.5) % (7)]; }

	void	jd_printToScreen(void);

};



#endif /* INC_JULIANDAY_H_ */
