/*
 * jd_printToScreen.cpp
 *
 *  Created on: 2 Jun 2024
 *      Author: jole
 */

//
// TODO
//

#include <iostream>
#include <iomanip>

#include "timestamp.h"
#include "julianday.h"



void julianday::jd_printToScreen(void)
{

	std::cout << std::fixed;

	std::cout << "Timestamp: " << jd_getDOW() << ", " << ts_getMonthName() << " " << (short)ts_getDay() << jd_getDaySuffix() << " " << ts_getYear() << std::endl;

	std::cout << "                  Julian Day(UTC, whole): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDay_utc << std::endl;
	std::cout << "                   Julian Date(fraction): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDate << std::endl;
	std::cout << "                                     doy: " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_doy << std::endl;

}
