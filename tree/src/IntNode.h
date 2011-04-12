/*
 * IntNode.h
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
 */

#ifndef INTNODE_H_
#define INTNODE_H_

#include "Node.h"

namespace trees {

class IntNode: public Node {
public:
	int value;

	IntNode();
	IntNode(childarray& children, int value);
	virtual ~IntNode();
};

}

#endif /* INTNODE_H_ */
