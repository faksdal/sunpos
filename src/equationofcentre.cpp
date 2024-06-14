/*
 * equationofcentre.cpp
 *
 *  Created on: 14 Jun 2024
 *      Author: jole
 */

#include <iostream>

#include "equationofcentre.h"



equationofcentre::equationofcentre(double _M, bool _verbose)
{

	eoc_verbose = _verbose;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){

		C_Table[i].C =		C_Table[i].C1 * sin(RADIANS(_M))
						+	C_Table[i].C2 * sin(2 * RADIANS(_M))
						+	C_Table[i].C3 * sin(3 * RADIANS(_M))
						+	C_Table[i].C4 * sin(4 * RADIANS(_M))
						+	C_Table[i].C5 * sin(5 * RADIANS(_M))
						+	C_Table[i].C6 * sin(6 * RADIANS(_M));


		if(eoc_verbose){
			std::cout	<< "Planet: " << C_Table[i].planet << " "
						<< C_Table[i].C1 << " "
						<< C_Table[i].C2 << " "
						<< C_Table[i].C3 << " "
						<< C_Table[i].C4 << " "
						<< C_Table[i].C5 << " "
						<< C_Table[i].C6 << " "
						<< C_Table[i].EC << " "
						<< C_Table[i].C
						<< std::endl;
		}

	}

}



equationofcentre::~equationofcentre()
{

}

