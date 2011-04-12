/*
 * OStack.cpp
 *
 *  Created on: Aug 25, 2010
 *      Author: aurelio
 */

#include "OStack.h"

namespace stack {

Stack::Stack()
{
	this->head=NULL;
}

Stack::~Stack()
{
	ElementNode* h = this->head;
	while(h) {
		this->head=this->head->next;
//POTENTIAL MEMORY LEAK		delete h->data;
		delete h;
		h=this->head;
	}
}


bool Stack::push(void *data)
{
	if ( ! this->head ) {
		this->head = new ElementNode(NULL, data);
	} else {
		this->head = new ElementNode( this->head, data );
	}
	return ( this->head != NULL );
}

void *Stack::pop()
{
	if ( ! this->head ) { return this->head; }
	ElementNode* h = this->head;
	this->head = this->head->next;
	void* data = h->data;
	delete h;
	return data;
}

Stack::ElementNode::ElementNode(ElementNode *next, void *data)
{
	this->next= next;
	this->data= data;
}

}





 // namespace stack



