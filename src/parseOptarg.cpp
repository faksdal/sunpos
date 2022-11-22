/*
 * parseOptarg.cpp
 *
 *	Created on: 13th of November 2022
 *	Author: jole
 */

#include "parseOptarg.h"



void parseOptarg(char **_optarg)
{
	//std::cout << "inside parseOptarg\n";
	while(**_optarg != '.' /*&& **_optarg != '-' */ && **_optarg != '/' && **_optarg != ':'){
		(*_optarg)++;
	}
	(*_optarg)++;
	return;
}
