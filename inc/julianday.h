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

#include <inttypes.h>
#include "timestamp.h"



class julianday : public timestamp{

private:
	//	Precision formatters for terminal printing
	short			jd_FLOATWIDTH, jd_FLOATPRECISION;

	int				jd_doy;
	//uint32_t		jd_julianDay;
	double			jd_julianDay;

	bool			jd_verbose;

	double			jd_julianDate;
	//double			jd_julianDayFraction;

	weekdays		jd_weekday;

	void	jd_calculateJulianDay(void);

public:
	julianday(int _year, short _month, double _day, short _hour, short _minute, double _second, bool _verbose);

};



#endif /* INC_JULIANDAY_H_ */
