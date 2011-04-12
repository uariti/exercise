/*
 * Node.h
 *
 *  Created on: Aug 23, 2010
 *      Author: aurelio
 */

#ifndef NODE_H_
#define NODE_H_
using namespace std;

namespace queue {

template <class T>
class Node{
	private:
		T* t;
	public:
		Node(T* t );

		virtual ~Node();
		T* getValue();

		Node* next;
};

template <class T>
Node<T>::Node(T* t) {
	this->t = t;
}

template <class T>
Node<T>::~Node() {
}

template<class T>
T* Node<T>::getValue()
{
	return this->t;
}

} //namespace queue



#endif /* NODE_H_ */
