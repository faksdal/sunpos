/*
 * jd_getDaySuffix.cpp
 *
 *  Created on: 2 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include <string>
#include "timestamp.h"
#include "julianday.h"



std::string julianday::jd_getDaySuffix(void)
{
	std::string retval = "th";

	switch((short)ts_getDay()){
		case 1:		retval = "st"; break;
		case 2:		retval = "nd"; break;
		case 3:		retval = "rd"; break;
		default:	break;
	} //switch()

	return(retval);
}
