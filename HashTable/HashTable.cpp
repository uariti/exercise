/*
 * HashTable.cpp
 *
 *  Created on: Oct 5, 2010
 *      Author: aurelio
 */

#include <string>
#include <iostream>

#include "HashTable.h"

HashItem::HashItem ( const char*  k, const int& value ) :
   value(value)
{
	int size = strlen ( k ) + 1;
	this->key = new char[size];
	memcpy (  this->key, k, size );
}

HashItem::HashItem ( HashItem& other) : key(other.key), value(other.value) {

}

HashItem::~HashItem() {
	delete[] this->key;
}


HashTable::HashTable(int size)
	:size( size ), count (0 )
{
	this->data = new HashItem* [this->size];
}

size_t HashTable::hasher(char *const & key) const
{
	int len = strlen ( key );
	size_t hash = 0;
	for( int i=0; i < len  ; i++ ) {
		hash ^=  ( i * key[i] );
	}

	return ( hash % this->size );
}

void HashTable::remove( char* const & key ) {
	HashItem* & hi = this->__get ( key );
	if ( ! hi ) return;
	delete hi;
	hi = 0;
	this->count--;
}

HashTable::~HashTable() {
	delete[] this->data;
}

HashItem* & HashTable::__get( char* const& key ) const {
	size_t index= this->hasher( key );
	return this->data[index];
}

int HashTable::get(char *const & key) const
{
	HashItem* item = this->__get(key);
	if ( ! item ) return 0;
	return item->value;
}



int HashTable::operator [](char *const & key ) const
{
	return this->get( key );
}

void HashTable::__insert( HashItem* & item ) {
	if ( ! item ) return;
	size_t index = this->hasher( item->key );
	this->data[index] = item;
	this->count++;
}

bool HashTable::insert(char *const & key, const int & value)
{
	HashItem* hi = new HashItem ( key, value );
	if ( this->__get(key) ) {
		this->remove( key );
	}
	if ( this->count == this->size - 1 ) {
		 std::cout.flush();
		 std::cerr <<  "Can not insert key " << key << ". "
				  "Use a growable hashtable. This one is full with " << this->count << std::endl;
		 std::cerr.flush();
		 return false;
	}
	this->__insert ( hi );
	return true;
}


