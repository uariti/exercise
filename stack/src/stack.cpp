//============================================================================
// Name        : stack.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "OStack.h"
#include "stackinha.h"
using namespace std;
using namespace stack;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	char str[]="Hello world";
	void* data = (void*) str;

//  stinode* si;
//	cout << "Staquinha: " << endl;
//	cout <<  "create: " << sticreate(&si) << endl;
//	cout <<  "insert:"  << stipush(&si, data ) << endl;
    Stack st;
    cout << "stack:" << st << endl;
    st.push( data );
    cout << "stack:" << st << endl;
    for (short i=10;i;i--){ st.push((void*)&str[i]); }
    cout << "stack:" << st << endl;
    for ( short i=15;i;i--) {
    cout << st.pop() << ",";
    }; cout << endl;
    cout << "stack:" << st << endl;
	return 0;
}
