/*
 * TheAirTripDivOne.cpp
 *
 *  Created on: Aug 28, 2010
 *      Author: aurelio
 */

#include "TheAirTripDivOne.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

namespace airtrip {

vector<string>& Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
	// Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
    return tokens;
}


TheAirTripDivOne::TheAirTripDivOne()
{
}

TheAirTripDivOne::~TheAirTripDivOne() {
}

    bool TheAirTripDivOne::bellmonford(unsigned int mintime)
    {
    	vector<int> citytime( this->number_of_cities, (int) this->time + 1 );
    	citytime[0] = 0;

    	for ( size_t c = 0; c < this->number_of_cities ; c++ ){
    		for ( size_t j = 0; j < this->number_of_lines; j++){
    			long t1 = citytime[this->data[A][j]] + (this->data[A][j]==0 ? 0 : mintime );
    			long flightnumber  = max<long>( 0, ( t1 - data[F][j] ) / data[P][j] );
    			if ( data[F][j] + data[P][j] * flightnumber < t1 ) {
    				flightnumber ++ ;
    			}
    			long t2 = data[F][j] + data[P][j] * flightnumber + data[T][j];
    			if ( citytime[data[B][j]] > t2 ) { citytime[data[B][j]] = t2; }
    		}
    	}
    	return citytime[this->number_of_cities - 1] <= this->time;
    }

    int TheAirTripDivOne::find(int n, string flights, int time)
    {
    	this->number_of_cities=n;
    	this->time = time;

    	vector<string> flightstk;
    	Tokenize (flights,flightstk );
    	if( ! flightstk.size() ) return -1;
    	int sz = flightstk.size();
		this->data = new int* [5];
    	for ( int i=0; i<5; i++) {
    		this->data[i] = new int[sz];
    	}
    	this->number_of_lines = flightstk.size();
    	for( size_t i=0; i< flightstk.size(); i++ ) {
    		vector<string> flightdetails;
    		Tokenize(flightstk[i], flightdetails, "," );
    		for ( size_t j=0; j<flightdetails.size(); j++){
    			stringstream str; str << flightdetails[j];
    			str >> data[j][i];
    		}
    	}
    	if ( ! this->bellmonford ( 1 ) ) return -1; //boundary conditions.
    	int left = 1, right = this->time + 1;
    	int mid = -1;
    	while ( right - left > 1 ) {
    		mid = (left+ right)/2;
    		if ( this->bellmonford(mid) ) {
    			left = mid;
    		} else {
    			right = mid;
    		}
    	}

    	return left;
    }

    int TheAirTripDivOne::tiago(int a) {
    	return 2;
    }

}
