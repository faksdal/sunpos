#include "sunpos.h"



void sunpos::spPrintOutput(void)
{
	//
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	cout << endl;
	cout	<< "Date/time: " << jdnGetJdnDay() << "/" <<  jdnGetJdnMonth() << "/" << jdnGetJdnYear() << " @ "
			<< setw(2) << setfill('0') << jdnGetJdnHour() <<":" << setw(2) << setfill('0')<< jdnGetJdnMinute() << ":" << setw(2) << setfill('0')<< jdnGetJdnSecond() << endl;
	cout	<< "Timezone: " << jdnGetJdnTz() << endl;
	cout	<< "Lat/Lon: " << setw(12) << setprecision(8) << spGetspLat() << "°/" << setw(12) << setprecision(8) << spGetspLon() << "°" << endl;
	cout << endl;


	//
	// custom numpunct with grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
	//
	struct my_numpunct : std::numpunct<char> {
		std::string do_grouping() const {return "\03";}
	};

	std::locale loc (std::cout.getloc(),new my_numpunct);
	std::cout.imbue(loc);


	cout	<< "      Julian Day Number (jdn): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) << setfill(' ') << jdnGetJdnMeeus() << endl;
	cout	<< "               Julian Century: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) << jdnGetJdnJulianCentury() << endl;
	cout	<< "Suns geometric mean longitude: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) <<  spGetGeomMeanLongSun() << endl;
	cout	<< "  Suns geometric mean anomaly: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) <<  spGetGeomMeanAnomSun() << endl;
	cout	<< "           spEccentEarthOrbit: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) <<  spGetEccentEarthOrbit() << endl;
	cout	<< "                 spSunEqOfCtr: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) <<  spGetSunEqOfCtr() << endl;
	cout	<< "                spSunTrueLong: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunTrueLong() << endl;
	cout	<< "                spSunTrueAnom: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunTrueAnom() << endl;
	cout	<< "               spSunRadVector: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunRadVector() << endl;
	/*
	cout	<< "                 spSunAppLong: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunAppLong() << endl;
	cout	<< "          spMeanObliqEcliptic: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetMeanObliqEcliptic() << endl;
	cout	<< "                  spOliqCorr: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetObliqCorr() << endl;
	cout	<< "                 spSunRtAscen: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunRtAscen() << endl;
	cout	<< "                  spSunDeclin: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunDeclin() << endl;
	cout	<< "                       spVarY: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetVarY() << endl;
	/*
	cout << "                 spEqOfTime: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGeteqOfTime() << endl;
	cout << "                spHaSunrise: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGethaSunrise() << endl;
	cout << " spLocalSolarNoon (decimal): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGtlocalSolarNoon() << endl;
	cout << "   spLocalSolarNoon (h:m:s): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << timeStringFromDecimal(getlocalSolarNoon()) << endl;

	if(spGetHaSunrise() != -1){
		cout << "             localSunRise: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << getlocalSunRise() << endl;
		cout << "     localSunRise (h:m:s): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << timeStringFromDecimal(getlocalSunRise()) << endl;
		cout << "              localSunSet: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << getlocalSunSet() << endl;
		cout << "     localSunSet (h:m:s): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << timeStringFromDecimal(getlocalSunSet()) << endl;
	}
	else{
		cout << "     Sun below horizon\n";
	}
	*/
	cout << endl;

	return;

}
