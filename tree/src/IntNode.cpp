/*
 * IntNode.cpp
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
 */

#include "IntNode.h"

namespace trees {

IntNode::IntNode()
:Node()
{
}

IntNode::IntNode(childarray& children, int value)
:Node(children)
{
	this->value = value;
}

IntNode::~IntNode() {
}

} // namespace tree
