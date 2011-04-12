/*
 * BinaryTree.h
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
using namespace std;

#include "BTNode.h"
using namespace trees;
namespace trees {

class BinaryTree {
public:
	BTNode* head;
	static long rotations;
	long getrotations() { return BinaryTree::rotations; }
public:
	BinaryTree();
	virtual ~BinaryTree();

	BTNode* insertValue( BTNode* root, int value);
	BTNode* findNode( BTNode* root, int value);

	static BTNode* rotateSingle( BTNode* root, int dir);
	static BTNode* rotateDouble( BTNode* root, int dir);

	void printPreorderTraversalNoRecursion (ostream& os, BTNode* root );
	void printPreorderTraversal (ostream& os, BTNode* root );
	ostream& printInorderTraversal (ostream& os, BTNode* root );
	void printPostorderTraversal (ostream& os, BTNode* root );

	static int checkHealth ( BTNode* node);
	int checkHealth() const;
	int insert( int data,  bool resetRotCounter=false );


private:
	static BTNode* insert_recursive ( BTNode* root, int data );
};



} //end namespace trees
#endif /* BINARYTREE_H_ */
