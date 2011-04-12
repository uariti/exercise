/*
 * Queue.h
 *
 *  Created on: Aug 23, 2010
 *      Author: aurelio
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Node.h"
#include <iostream>

using namespace std;
namespace queue {

template <class T>
class Queue {
private:
	Node<T>* head;
	Node<T>* currentNode;
public:
	Queue();
	virtual ~Queue();

	Node<T>* getQueue() { return this->head; }
	Node<T>* insert (T* t);
	Node<T>* insertAndLink(T* t, Node<T>* n);
	bool  remove(Node<T>* n);
	bool  remove(T* t);
	void  destroy(Node<T>* t);
	T* pop ();

	bool isCircular();

	friend ostream & operator<<( ostream & os, Queue<T>* q) {
		os << "List: ";
		Node<T>* n=q->getQueue();
		if ( ! n ) { os << "[empty]"; }
		for (  ;n; n=n->next ) {
			os << *(n->getValue());
			if ( n->next ) { os << ","; }
		}
		return os;
	}
};

template<class T>
Queue<T>::Queue()
{
	this->head = 0;
}

template<class T>
Queue<T>::~Queue()
{
	this->destroy(this->head);
}

template<class T>
void Queue<T>::destroy(Node<T>* n)
{
	if ( ! this->head ) { return; }
	if ( ! n ) { return; }
	Node<T>* h = this->head;
	if ( n && h != n ) {
		for ( ;h->next &&  (h->next != n); h=h->next);
	}
	do {
		Node<T>* n1=h;
		h = n1->next;
		delete(n1);
	} while ( h );
}


template<class T>
Node<T>*  Queue<T>::insert (T* t)
{
	try {
	if ( ! this->head ) {
		this->head=new Node<T>(t);
		this->head->next = 0;
		return this->head;
	}
	Node<T>* n = this->head;
	while ( n->next && *(n->next->getValue()) < *t ) { n = n->next; }
	Node<T>* node = new Node<T>(t);
	node->next = n->next;
	n->next = node;
    return node;
	} catch ( exception& e ){
		cerr << e.what() << endl;
		return 0;
	}
}

template<class T>
Node<T>* Queue<T>::insertAndLink( T* t, Node<T>* n) {
	Node<T>* inserted = this->insert ( t );
	this->destroy( inserted->next );
	inserted->next = n;
	return inserted;
}

template<class T>
bool Queue<T>::isCircular()
{
	if( ! this->head || ! this->head->next ) { return false; }
	Node<T>* slow=this->head;
	Node<T>* fast=slow->next;
	while ( fast != slow &&  ( fast = fast->next ) != slow  ) {
		if ( ! fast || ! fast->next ) { return false; }
		fast = fast->next;
		slow = slow->next;
	}
	return true;
}



template<class T>
bool Queue<T>::remove(T* t)
{
	Node<T>* n = this->head;
	if ( ! n ) { return false; }
	if ( *(n->getValue()) == *t ) {
		this->head = n->next;
		delete ( n);
		return true;
	}
	while ( *(n->next->getValue()) == *t ) {
		Node<T>* d=n->next;
		n->next = n->next->next;
		delete d;
		return true;
	}
	return false;
}

template<class T>
bool Queue<T>::remove(Node<T>* n)
{
	Node<T>* h=this->head;
	if ( h == n ) {
		this->head = h->next;
		delete h;
		return true;
	}
	while (h) {
		if ( h->next == n ) {
			h->next=h->next->next;
			delete n;
			return true;
		}
	}
	return false;
}

template<class T>
T* Queue<T>::pop()
{
	if ( ! this->head ) { return 0; }
	Node<T>* n = this->head;
	this->head = n->next;
	T* value = n->getValue();
	delete n;
	return value;
}


} //namespace queue



#endif /* QUEUE_H_ */
