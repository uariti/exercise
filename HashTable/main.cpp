/*
 * main.cpp
 *
 *  Created on: Oct 5, 2010
 *      Author: aurelio
 */

#include "HashTableLinearProbbing.h"

#include <iostream>


int main ( int argc, char* argv[] ) {
	HashTableLinearProbbing ht( 11 );
	std::cout << "Insert aa" << std::endl;
	ht.insert("aa",1);
	std::cout << ht << std::endl;

	std::cout << "Insert bb" << std::endl;
	ht.insert("bb",2);
	std::cout << ht << std::endl;

	std::cout << "Get aa,bb,cc" << std::endl;
	std::cout << ht.get("aa") << std::endl;
	std::cout << ht["bb"] << std::endl;
	std::cout << ht["cc"] << std::endl;

	std::cout << "test remove " << std::endl;
	ht.remove("aa");
	std::cout << ht <<  std::endl;

	std::cout << "test replace";
	ht.insert ("dd", 5);
	ht.insert ("dd", 6);
	ht.insert( "dd", 7);
	std::cout << ht << std::endl;

	std::cout << "test collision";
	ht.insert ( "aa0", 1);
	ht.insert ( "aa1", 1);
	ht.insert ( "aa2", 1);
	ht.insert ( "aa3", 1);
	ht.insert ( "aa4", 1);
	ht.insert ( "aa5", 1);
	ht.insert ( "aa6", 1);
	std::cout << ht << std::endl;

	std::cout << "fim" << std::endl;
	return 0;
}
