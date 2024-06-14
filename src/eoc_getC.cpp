/*
 * eoc_getC.cpp
 *
 *  Created on: 14 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "equationofcentre.h"



double equationofcentre::eoc_getC(std::string _planet)
{
	double retval = 0.;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){

		// Compare planets in list with the one asked for by _planet
		if(C_Table[i].planet == _planet){
			retval = C_Table[i].C;

			/*
			if(ma_verbose)
				std::cout << "Found the planet " << M01[i].planet << " with value of M " << M01[i].M << std::endl;
			*/

			break;
		}
	}

	return retval;
}
