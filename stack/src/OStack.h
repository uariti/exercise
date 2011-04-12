/*
 * Stack.h
 *
 *  Created on: Aug 25, 2010
 *      Author: aurelio
 */

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

using namespace std;

namespace stack {

class Stack {
public:
	Stack();
	virtual ~Stack();

protected:
	class ElementNode {
	public:
		ElementNode( ElementNode* next, void* data);
		ElementNode* next;
		void* data;
		friend ostream& operator<<(ostream& os, ElementNode* el) {
			if ( ! el ) { os << "NULL"; }
			else {
				void *x = (void*) el;
				os << (unsigned long) x;
				//os << x;
			}
			return os;
		}
	};
	ElementNode* head;

public:
	bool push ( void* data );
	void* pop ( );
	friend ostream& operator<<(ostream& os, Stack& st) {
		ElementNode* el = st.head;
		while ( el ) {
			os << el << ",";
			el = el->next;
		}
		os << "NULL";
		return os;
	}
};

} //namespace stack

#endif /* STACK_H_ */
