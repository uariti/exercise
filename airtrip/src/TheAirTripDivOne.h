/*
 * TheAirTripDivOne.h
 *
 *  Created on: Aug 28, 2010
 *      Author: aurelio
 */

#ifndef THEAIRTRIPDIVONE_H_
#define THEAIRTRIPDIVONE_H_

#include <string>
using namespace std;

namespace airtrip {

class TheAirTripDivOne {
private:
	int ** data;
	size_t number_of_cities;
	size_t number_of_lines;
	int time;
	enum flightdata {A=0,B,F,T,P};

	bool bellmonford(unsigned int mintime);
public:
	TheAirTripDivOne();
	virtual ~TheAirTripDivOne();

	static int tiago(int a);


	int find ( int n, string flights, int time );
};

}

#endif /* THEAIRTRIPDIVONE_H_ */
