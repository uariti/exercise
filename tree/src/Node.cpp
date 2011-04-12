/*
 * Node.cpp
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
 */

#include "Node.h"

namespace trees {



Node::Node() {
}

Node::~Node() {
}

Node::Node(childarray children) {
	this->children.swap(children);
}

int Node::getNumChildren() const
{
	return (int) this->children.size();
}


Node *Node::getChild(int index) const
{
	if ( this->getNumChildren() < index ) { return 0; }
	return this->children[index];
}

int Node::addChild(Node* const & node)
{
	this->children.push_back( node );
	return this->getNumChildren();
}


} //namespace trees



