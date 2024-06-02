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

	Values for m0 and m1 can be taken from the following table

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



class meananomaly{

	double	M, M0, M1;
public:
	meananomaly();
	virtual ~meananomaly();

	double	ma_getM(void)	{return M;}
};

#endif /* INC_MEANANOMALY_H_ */
