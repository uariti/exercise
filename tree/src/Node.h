/*
 * Node.h
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>
using namespace std;

namespace trees {

class Node {
public:
	typedef vector<Node*> childarray;

	Node();
	Node(childarray children);
	virtual ~Node();

	childarray children;

	int getNumChildren() const;
	Node* getChild( int index ) const;
	int addChild( Node* const & node );
	childarray& getChildren() { return this->children; }
};

}

#endif /* NODE_H_ */
