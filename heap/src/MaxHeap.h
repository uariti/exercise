/*
 * MaxHeap.h
 *
 *  Created on: Oct 6, 2010
 *      Author: aurelio
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include <stddef.h>
#include <iostream>

typedef unsigned long ulong;

class MaxHeap {
private:
	int* theheap;
	size_t size;
	size_t heapsize;
protected:
public:
	void heapify(int index);
	int parent (const int& index) const { return ((index-1) >> 1 ); }
	int left (const int& index ) const { return ((index+1) << 1 ) - 1; }
	int right(const int& index ) const { return left(index) + 1; }
	void swapit( const int i1, const int i2 )
		{ int tmp=theheap[i1]; theheap[i1]=theheap[i2]; theheap[i2]=tmp; }
	void buildArray();
public:
	int getSize() const { return (int) this->size; }
	int getHeapSize() const { return (int) this->heapsize; }
	MaxHeap(size_t size= 1000);
	MaxHeap( int * const & array, size_t size );
	void buildHeap();
	virtual ~MaxHeap();

	void heapSort();
public:
	friend std::ostream& operator<< ( std::ostream & out, MaxHeap& hp ) {
		out << "[";
		for ( int i=0;i < hp.getSize() - 1;i++) {
			out <<  hp.theheap[i] << "," ;
		}
		if ( hp.getSize() )
			out << hp.theheap[hp.getSize()-1];
		out << "]";
		return out;
	}
};



#endif /* MAXHEAP_H_ */
