/*
 * meananomaly.cpp
 *
 *  Created on: 2 Jun 2024
 *      Author: jole
 */

#include <math.h>
#include <string>
#include <iomanip>
#include <iostream>

#include "meananomaly.h"



meananomaly::meananomaly(double _jd, double _j2000, bool _verbose)
{
	ma_verbose = _verbose;



	if(_verbose){
		std::cout << "----------------- Mean anomaly table -----------------" << std::endl;
		std::cout << "Element\tPlanet\t     M0\t\t     M1\t\t  M"<< std::endl;
		std::cout << "------------------------------------------------------" << std::endl;
	}

	std::cout << std::fixed;
	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){
		//M01[i].M = (long)(M01[i].M0 + M01[i].M1 * (_jd - _j2000)) % 360;
		//M01[i].M = (M01[i].M0 + M01[i].M1 * (_jd - _j2000)) % 360.0);
		M01[i].M = fmod( (M01[i].M0 + M01[i].M1 * (_jd - _j2000)), 360);


		if(ma_verbose){
			std::cout	<< "M01[" <<i << "]: " << M01[i].planet << "\t"
						<< std::setw(11) << std::setprecision(7) << M01[i].M0 << "\t"
						<< std::setw(11) << std::setprecision(7) << M01[i].M1 << "\t"
						<< std::setw(9) << std::setprecision(5) << M01[i].M
						<< std::endl;
		}
	}
	if(ma_verbose)
		std::cout << "------------------------------------------------------" << std::endl;


}

meananomaly::~meananomaly()
{

}

