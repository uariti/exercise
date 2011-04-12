/*
 * MaxHeap.cpp
 *
 *  Created on: Oct 6, 2010
 *      Author: aurelio
 */
#include "string.h"
#include "MaxHeap.h"


MaxHeap::MaxHeap(size_t size):
	size(size), heapsize( size )
{
	this->theheap = new int[size];
	// already in the heap state. this->heapify(0);
}

void MaxHeap::buildArray() {
	for ( int i=(int)this->size;i>=0;--i) {
		this->theheap[i]=i;
	}
}

void MaxHeap::heapify(int index)
{
	int left = this->left( index );
	int right= this->right(index );
    int largest = index;
	if ( left < this->getHeapSize() && theheap[left] > theheap[largest] ) {
		largest=left;
    }
	if( right < this->getHeapSize() && theheap[right] > theheap[largest] ) {
		largest = right;
	}
	if ( largest != index ) {
		swapit ( largest, index  );
		return heapify ( largest );
	}
}

MaxHeap::MaxHeap( int * const & array, size_t size )
{
	this->size=size;
	this->heapsize=size;
	this->theheap = new int[size];
	memcpy( this->theheap, &array[0], size * sizeof( array) );
//	this->buildHeap();
}

void MaxHeap::buildHeap() {
	for( int i=this->parent(this->getSize()-1); i >= 0; --i ) {
		this->heapify( i );
	}
 }

MaxHeap::~MaxHeap() {
	delete[] this->theheap;
	// TODO Auto-generated destructor stub
}

void MaxHeap::heapSort() {
	for( int i= this->getSize() - 1; i >= 0; --i ) {
		this->swapit( 0, i);
		this->heapsize--;
		this->heapify(0);
	}
}
