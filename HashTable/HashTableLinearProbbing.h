/*
 * HashTableLinearProbbing.h
 *
 *  Created on: Oct 5, 2010
 *      Author: aurelio
 */

#ifndef HASHTABLELINEARPROBBING_H_
#define HASHTABLELINEARPROBBING_H_

#include "HashTable.h"

class HashTableLinearProbbing: public HashTable {
protected:
    virtual HashItem* & __get( char* const & key ) const;
    virtual size_t probe ( size_t index ) const;
	void __insert( HashItem* & item );
public:
	HashTableLinearProbbing(int size = 1000):HashTable(size) {};
	virtual ~HashTableLinearProbbing();
};

#endif /* HASHTABLELINEARPROBBING_H_ */
