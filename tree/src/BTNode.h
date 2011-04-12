/*
 * BinaryTree.h
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
 */

#ifndef BTNODE_H_
#define BTNODE_H_
#include <iostream>
using namespace std;

namespace trees {

class BTNode {
private:
	BTNode* left;
	BTNode* right;
	BTNode* child;
	int value;
public:
	BTNode(BTNode* left, BTNode* right, int value);
	BTNode(BTNode& n) { this->left = n.getLeft(); this->right=n.getRight(); this->value=n.getValue(); };
	BTNode();
	virtual ~BTNode();

	enum redblack { RED, BLACK };
	redblack color;

	BTNode* getLeft() const;
	BTNode* getRight() const;
	BTNode* getChild(bool right = false ) const;
	BTNode* setChild(bool right = false, BTNode* n = 0);
	int getValue() const;
	static bool isRed( BTNode* n) { return ( n && n->color==RED); };
	static void setRed(BTNode* n) { n->color=RED; }
	static void setBlack(BTNode* n){n->color=BLACK;}
	bool isRed() { return BTNode::isRed( this ); }
	void setRed() { this->color=RED;}
	void setBlack(){ this->color=BLACK; }
	friend ostream & operator<<( ostream & os, BTNode& n) {
		os << n.value;
		return os;
	}
};

inline
BTNode* BTNode::getChild(bool right ) const
{
	return (right)?this->getRight():this->getLeft();
}



} //end namespace trees
#endif /* BTNODE_H_ */
