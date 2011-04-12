//============================================================================
// Name        : linkedlist.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

#include "Queue.h"
using namespace queue;


struct data {
	string phone;
	int priority;
	data(){ this->priority = -1; };
	data(const string& phone, const int& priority) { this->phone=phone;this->priority=priority;}
	bool operator< (const data& d1) const { return ( this->priority < d1.priority ); }
	bool operator==(const data& d1) const { return ( this->priority==d1.priority&&this->phone==d1.phone); }
	friend ostream & operator<<( ostream & os, const data d) {
		if ( d.priority < 0 ) {
			os << "blank";
		} else {
			os << d.phone << "[" << d.priority << "]";
		}
		return os;
	}
	friend ostream & operator<<( ostream & os, const data * d) {
		if ( ! d ) { os << "[null]"; return os; }
		os << *d ;
		return os;
	}

};




typedef Node<int> nint;

int main(int argc, char* argv[] ) {


	Queue<data>* q= new Queue<data>();
	if ( argc && strcmp(argv[0],"perf")==0 ) {
	//cout << q << endl;
	int max=100000;
	for ( int x=1; x<max; x++ ) {
		q->insert( new data("x",x % 10) );
		//if ( !(x % 100 ) ) {  cout << x << ","; }
	}
	//cout << "pop" << endl;
	for ( int y=max -1; y > 0; y-- ) {
		q->pop();
		//if ( ! (y%100) ) { cout << y << ":"; }
	}
	 cout << "done" << endl;

	// cout <<  q << endl;
	delete q;
	return 0;
	} //if argc...
	q->insert( new data("a", 1) );      cout << q << endl;
	Node<data>* n = q->insert( new data("a1", 1) );      cout << q << endl;
	q->insert( new data("b",3 ) );      cout << q << endl;
 	q->insert( new data("c",2 ) );   	cout << q << endl;
 	cout << q->isCircular() << endl;
	q->insertAndLink( new data("d",2 ), n );      cout << q->isCircular() << endl;
	return 0;
	q->insert( new data("e",1 ) );      cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << "pop: " <<  q->pop() << endl; cout << q << endl;
	cout << q << endl;
 	delete q;

	return 0;
}
