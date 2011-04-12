//============================================================================
// Name        : heap.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main() {
	cout << "keys" << endl;
	MaxHeap mh1(5);
	for ( int i = 0 ;i < 5; i++ ) {
	cout << i << " l: " << mh1.left(i)
			  << " r: " << mh1.right(i)
			  << " p: " << mh1.parent(i)
			  << endl;
	}

	cout << "mh5" << endl;
	int a[]= {3,2,4,1,5,6};
	MaxHeap mh( &a[0], (size_t) (sizeof(a)/sizeof(*a)) );
	cout << mh << endl;
	cout << "heapify(0)" << endl;
	mh.heapify(0);
	cout << mh << endl;

	cout << "mh 10 " << endl;
	MaxHeap mh10 ( 10 ); mh10.buildArray();
	cout << mh10 << endl;
	cout << "build heap" << endl;
	mh10.buildHeap();
	cout << "mh10" << mh10 << endl;
    mh.buildHeap();
    cout << "mh" << mh << endl;

    cout << "sort" << endl;
    mh.heapSort();
    cout << "mh" << mh << endl;
    mh10.heapSort();
    cout << "mh10" << mh10 << endl;

    return 0;
}
