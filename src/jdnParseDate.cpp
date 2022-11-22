/*
 * jdnParseDate.cpp
 *
 *	Created on: 20 Nov 2022
 *	Author: jole
 *
 *	Saved function jdnParseDate in its own file
 *
 *	This function takes care of checking the user inputs a valid date, and also that we use the
 *	correct algorithm whether we're in Julian or Gregorian calendar.
 *      
 *
 */

#include <stdio.h>
#include "jdn.h"



void jdn::jdnParseDate(void)
{
	// we assume a valid Gregorian date, otherwise this is changed in the below switch{...}/if{...}-statement
	jdnValidDate		= true;
	jdnGregorianDate	= true;

	// if we're in 1582, check for valid date
	if(jdnYear == 1582 && jdnMonth == 10){
		switch(jdnDay){
		case 1:
		case 2:
		case 3:
		case 4:		jdnGregorianDate = false;
					break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:	printf("\n No such date!\n Exiting...\n");
					jdnValidDate = false;
					exit(-1);
					break;
		default:	break;
		}
	}
	else if(jdnYear == 1582 && jdnMonth < 10){
		jdnGregorianDate = false;
		//printf("\nYear == 1582 and month is less than 10.\n");
	}
	else if(jdnYear < 1582){
		jdnGregorianDate = false;
		//printf("\nYear is less than 1582.\n");
	}
}
