/*
 * HashTableLinearProbbing.cpp
 *
 *  Created on: Oct 5, 2010
 *      Author: aurelio
 */
#include <iostream>

#include "HashTableLinearProbbing.h"



HashItem *& HashTableLinearProbbing::__get(char *const & key) const
{
	size_t index= this->hasher( key );
	HashItem** hi = &( this->data[index] );
	while ( *hi && strcmp( key, (*hi)->key ) != 0  ) {
		index = this->probe( index );
		hi = & (this->data[index]);
	}
	return (*hi);
}

void HashTableLinearProbbing::__insert( HashItem* & item ) {
	if ( ! item ) return;
	size_t index = this->hasher( item->key );
	while ( this->data[index] ) {
		index = this->probe ( index );
	}
	this->data[index] = item;
	this->count++;
}

size_t HashTableLinearProbbing::probe( size_t index ) const
{
	//TODO: offset 3 should be any non divisor of this->size.
	size_t offset = 3;
	return (( index + offset ) % this->size);
}

HashTableLinearProbbing::~HashTableLinearProbbing() {
}


