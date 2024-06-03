/*
 * ma_getM.cpp
 *
 *  Created on: Jun 3, 2024
 *      Author: leijon
 */

//
// TODO -
//

#include <iostream>

#include "meananomaly.h"



double meananomaly::ma_getM(std::string _planet)
{
	double retval = 0.;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){

		// Compare planets in list with the one asked for by _planet
		if(M01[i].planet == _planet){
			retval = M01[i].M;
			/*
			if(ma_verbose)
				std::cout << "Found the planet " << M01[i].planet << " with value of M " << M01[i].M << std::endl;
			*/
			break;
		}
	}

	return retval;
}
