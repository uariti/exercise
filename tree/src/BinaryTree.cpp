/* BinaryTree.cpp
 *
 *  Created on: Aug 24, 2010
 *      Author: aurelio
*/

#include "BinaryTree.h"
namespace trees {

long BinaryTree::rotations = 0;

BinaryTree::BinaryTree()
{
	this->head = NULL;
}

BinaryTree::~BinaryTree()
{
}


BTNode *BinaryTree::findNode(BTNode *root, int value)
{
	while ( root ) {
			int v= root->getValue();
			if ( value == v ) break;
			if ( value > v )  root=root->getRight();
			if ( value < v )  root=root->getLeft();
	}
	return root;
}

void BinaryTree::printPreorderTraversal(ostream& os,BTNode *root)
{
	if ( root ) {
		os << *root << ",";
		this->printPreorderTraversal( os, root->getLeft() );
		this->printPreorderTraversal( os, root->getRight() );
	}
}

void BinaryTree::printPreorderTraversalNoRecursion(ostream& os,BTNode *root)
{
	os << "NI";
}

    BTNode *BinaryTree::insertValue(BTNode *root, int value)
    {
    	if ( ! root ) {
    		root = new BTNode(0,0,value); return root;
    	}
    	int dir = ( value < root->getValue() );
    	return root->setChild ( dir, this->insertValue( root->getChild(dir), value ) );
    }

    BTNode *BinaryTree::rotateSingle(BTNode *root, int dir)
    {
    	BTNode* save = root->getChild( ! dir );
    	root->setChild(! dir, save->getChild(dir));
    	save->setChild(dir, root);

    	save->setBlack();
    	root->setRed();
    	BinaryTree::rotations++;
    	return save;
    }

    BTNode *BinaryTree::rotateDouble(BTNode *root, int dir)
    {
    	if  ( ! root ) return root;
    	root->setChild( !dir, BinaryTree::rotateSingle( root->getChild( !dir ), !dir ));
    	return BinaryTree::rotateSingle(root, dir);
    }



void BinaryTree::printPostorderTraversal(ostream& os,BTNode *root)
{
	if ( root ) {
		this->printPostorderTraversal( os, root->getLeft() );
		this->printPostorderTraversal( os, root->getRight() );
		os << *root << ",";
	}
}



ostream& BinaryTree::printInorderTraversal(ostream& os,BTNode *root)
{
	if ( root ) {
		this->printInorderTraversal( os, root->getLeft() );
	    os << *root << ";";
		this->printInorderTraversal( os, root->getRight() );
	}
	return os;
}

int BinaryTree::checkHealth(BTNode *root)
    {
    	int lh, rh;
    	if ( ! root) { return true; }
    	BTNode* ln = root->getLeft();
    	BTNode* rn = root->getRight();

    	/* Consecutive red links */
    	if ( root->isRed() ) {
    		if ( BTNode::isRed(ln) || BTNode::isRed(rn) ) {
    			cerr << "Red violation" << endl;
    			return 0;
    		}
    	}

    	lh = BinaryTree::checkHealth( ln );
    	rh = BinaryTree::checkHealth(rn);

    	/* Invalid binary search tree */
    	if (   ( ln && ln->getValue() >= root->getValue() )
    		|| ( rn && rn->getValue() <= root->getValue() ) )
    	{
    		cerr << "Binary tree violation" << endl;
    		return 0;
    	}

    	/* Black height mismatch */
    	if ( lh && rh && lh != rh ) {
    		cerr << "Black violation" << endl;
    		return 0;
    	}

    	/* Only count black links */
    	if ( lh && rh ) {
    		return BTNode::isRed( root ) ? lh : lh + 1;
    	} else {
    		return 0;
    	}

    }

    int BinaryTree::insert(int data, bool resetRotCounter)
    {
    	if ( resetRotCounter ) BinaryTree::rotations = 0;
    	this->head = BinaryTree::insert_recursive( this->head, data );
    	this->head->setBlack();
    	return 1;
    }

    int BinaryTree::checkHealth() const
    {
    	return BinaryTree::checkHealth( this->head );
    }


    BTNode* BinaryTree::insert_recursive(BTNode *root, int data)
    {
    	if ( ! root ) {
    		root= new BTNode(NULL,NULL,data);
    		return root;
    	}
    	if ( data == root->getValue() ) {
    		return root;
    	}
    	int dir = root->getValue() < data;
    	root->setChild(dir, BinaryTree::insert_recursive( root->getChild(dir), data ));
    	if ( BTNode::isRed( root->getChild(dir) )) {
    		if ( BTNode::isRed(root->getChild(!dir))) {
    			/* Case 1 */
    			root->setRed();
    			root->getChild(dir)->setBlack();
    			root->getChild(!dir)->setBlack();
    		} else {
    			/* Case 2 and 3 */
    			if ( BTNode::isRed(root->getChild(dir)->getChild(dir) ) ) {
    				root = BinaryTree::rotateSingle( root, !dir );
    			} else if ( BTNode::isRed(root->getChild(dir)->getChild(!dir))) {
    				root = BinaryTree::rotateDouble( root, !dir );
    			}
    		}
    	}
    	return root;
    }

} // namespace trees
