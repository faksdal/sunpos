/*
 * meananomaly.h
 *
 *  Created on: 2 Jun 2024
 *      Author: jole
 */
/*
	Source: https://www.aa.quae.nl/en/reken/zonpositie.html

	The mean anomaly of the planets in degrees, can to a reasonable degree of accuracy
	be calculated using the following formula, for a date given as a Julian Day Number (whole), j :

	M		= (M0 + M1(j - j2000)) mod 360°
	j2000	= 2'451'545

	Values for M0 and M1 can be taken from the following table

	M0 is the mean anomaly at a fixed moment
	M1 is the rate of change of the mean anomaly

	|-----------|---------------|---------------|
	| 			|      M0		|      M1 		|
	|-----------|---------------|---------------|
	|Mercury	| 	174.7948	| 	4.09233445	|
	|-----------|---------------|---------------|
	|Venus		| 	50.4161		| 	1.60213034	|
	|-----------|---------------|---------------|
	|Earth		| 	357.5291	| 	0.98560028	|
	|-----------|---------------|---------------|
	|Mars		| 	19.3730		| 	0.52402068	|
	|-----------|---------------|---------------|
	|Jupiter 	|	20.0202		| 	0.08308529	|
	|-----------|---------------|---------------|
	|Saturn 	|	317.0207	| 	0.03344414	|
	|-----------|---------------|---------------|
	|Uranus 	|	141.0498	| 	0.01172834	|
	|-----------|---------------|---------------|
	|Neptune	| 	256.2250	| 	0.00598103	|
	|-----------|---------------|---------------|
	|Pluto		| 	14.882 		|	0.00396		|
	|-----------|---------------|---------------|
*/



#ifndef INC_MEANANOMALY_H_
#define INC_MEANANOMALY_H_

#include <string>

#define	NUMBEROFPLANETS	9



class meananomaly{

	struct M01_fixed {
		std::string	planet;
		double		M0, M1, M;
	};

	bool	ma_verbose;

	//std::string	planets[]	=	{"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};

	M01_fixed	M01[NUMBEROFPLANETS] = {	"Mercury",	174.7948000,	4.09233445, 0.,
											"Venus",	50.41610000,	1.60213034, 0.,
											"Earth",	357.5291000,	0.98560028, 0.,
											"Mars",		19.37300000,	0.52402068, 0.,
											"Jupiter",	20.02020000,	0.08308529, 0.,
											"Saturn",	317.0207000,	0.03344414, 0.,
											"Uranus",	141.0498000,	0.01172834, 0.,
											"Neptune",	256.2250000,	0.00598103, 0.,
											"Pluto",	14.88200000,	0.00396000,	0.};

	//enum class planets {Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto};

public:
	meananomaly(double _jd, double _j2000, bool _verbose);
	virtual ~meananomaly();

	double	ma_getM(std::string _planet);
};

#endif /* INC_MEANANOMALY_H_ */
