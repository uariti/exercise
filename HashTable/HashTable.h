/*
 * HashTable.h
 *
 *  Created on: Oct 5, 2010
 *      Author: aurelio
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stddef.h>
#include <iostream>

//TODO: IMPLEMENT LINKED LIST TO USE INTO HASHITEM WHEN THERE ARE COLLISIONS.

class HashItem {
public:
	char*  key;
	const int value;
	HashItem ( const char*  key, const int& value );
	HashItem ( HashItem& other);
	virtual ~HashItem();

	friend std::ostream& operator<< ( std::ostream & out, HashItem& hi ) {
		out <<  hi.key << "," << hi.value;
		return out;
	}
};

class HashTable {
protected:
	size_t size;
	size_t count;
	HashItem** data;
    virtual size_t hasher ( char* const & key ) const;
    virtual HashItem* & __get( char* const & key ) const;
    virtual void __insert ( HashItem* & item );
public:
    size_t getSize() const { return this->size; }
    int getCount() const { return this->count; }
	HashTable(int size = 1000);
	virtual ~HashTable();

	virtual bool insert ( char* const & key, int const & value );
	virtual int get ( char* const & key) const;

	int operator[] ( char* const & key ) const;

	virtual void remove( char* const & key );

	friend std::ostream& operator<< ( std::ostream & out, HashTable& ht )  {
		for( size_t i = 0; i< ht.size; i++ ) {
			if( ht.data[i] ) {
				out << "[" << i << "]=" << *(ht.data[i]) << " : ";
			}
		}
		out << ".";
		return out;
	}
};

#endif /* HASHTABLE_H_ */
