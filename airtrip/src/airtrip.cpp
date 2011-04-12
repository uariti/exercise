//============================================================================
// Name        : airtrip.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "TheAirTripDivOne.h"
using namespace airtrip;

int main() {
	cout << "!!!Mo viagem!!!" << endl; // prints !!!Hello World!!!

	string f = "0,1,1,4,7 1,2,9,1,10";

	TheAirTripDivOne air;

	cout << air.find(3,f,20) << endl;


	return 0;
}
