/* BinaryTree.cpp
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
*/

#include "BTNode.h"
#include <iostream>
namespace trees {

BTNode::BTNode() {
	this->left=0;
	this->right=0;
	this->color=RED;
	this->value=0;
}

BTNode::BTNode(BTNode *left, BTNode *right, int value)
{
	this->left = left;
	this->right= right;
	this->color = RED;
	this->value= value;
}

BTNode::~BTNode() {
}

BTNode *BTNode::getLeft() const
{
	return this->left;
}

BTNode *BTNode::getRight() const
{
	return this->right;
}

BTNode *BTNode::setChild(bool right, BTNode* n)
{
   	if ( right ) {
   		this->right = n;
   	} else {
   		this->left = n;
   	}
 	return n;
}

int BTNode::getValue() const
{
	return this->value;
}

} // namespace trees
