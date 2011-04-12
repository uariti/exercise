//============================================================================
// Name        : phonenumber.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printTelephoneWords( int phoneNum[] );
void printTelephoneWords2( int phoneNum[] );

int main() {
	int number[] = { 1,1,1,1,1,1,3 };
	 printTelephoneWords( number ); // prints O imundo
	 cout << "----------" << endl;
	 printTelephoneWords2( number );
	 return 0;
}

char phonekeys[][5] = { "0000", "1111", "abc2", "def3", "ghi4", "jkl5", "mno6", "prs7", "tuv8", "wxy9" };

char getCharKey ( int digit, int position ) {
	return phonekeys[digit][position];
}

void doPrintTelephoneWords( int phoneNum[], int curDigit, char result[] ) {
	if( curDigit == 7 ) {
		cout << result << endl;
		return;
	}
	for ( int i=0; i<3;i++) {
		result[curDigit] = getCharKey ( phoneNum[curDigit], i);
		doPrintTelephoneWords( phoneNum, curDigit + 1, result );
		if ( phoneNum[curDigit] == 0 || phoneNum[curDigit] == 1) {
			return;
		}
	}
}

void printTelephoneWords( int phoneNum[] ) {
	char result[] = "      ";
	doPrintTelephoneWords( phoneNum, 0, result );
}


void printTelephoneWords2( int phoneNum[] ){
	char result[] = "       ";
	int i;
	int j=0;
	for ( i=0; i<7;i++ )
		result[i] = getCharKey( phoneNum[i],0);
	while( true ) {
		cout << result << endl;
		for ( i=6; i>=-1; i-- ) {
			if ( i==-1) return;
			char curr = result[i];
			int k = phoneNum[i];
			if( k==0 || k==1 ) {
				j=0;
			} else if ( curr == getCharKey(k,0) ) {
				j=1;
			} else if ( curr == getCharKey(k,1) ) {
				j=2;
			} else if ( curr == getCharKey(k,2) ) {
				j=0; //loop.
			}
			result[i] = getCharKey(k,j);
			if ( j ) break;
		}
	}
}
