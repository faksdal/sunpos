/*
 * julianday.h
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */

#ifndef INC_JULIANDAY_H_
#define INC_JULIANDAY_H_

#include "timestamp.h"



class julianday : public timestamp{

private:
	//	Precision formatters for terminal printing
	short		jd_FLOATWIDTH, jd_FLOATPRECISION;

	int			jd_doy;

	bool		jd_verbose;

	double		jd_julianDay;
	double		jd_julianDayFraction;

	weekdays	jd_weekday;

	void	jd_calculateJulianDay(void);

public:
	julianday(int _year, short _month, double _day, short _hour, short _minute, double _second, bool _verbose);

};



#endif /* INC_JULIANDAY_H_ */
