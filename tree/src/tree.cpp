//============================================================================
// Name        : tree.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Node.h"
#include "IntNode.h"
#include "BTNode.h"
#include "BinaryTree.h"

using namespace trees;

int main() {
	Node* aa = new Node();
	Node* aaa = new Node();
	for ( int k=23;k;k--) {
		aa->addChild( aaa );
	}
	cout << "23 = " << aa->getNumChildren() << endl;

	Node* bb = new Node ( aa->getChildren() );
	bb->addChild( aaa );
	cout << "24 = " << bb->getNumChildren() << endl;

	Node* cc = new IntNode( aa->getChildren(),2  );
	cout << "23 = " << cc->getNumChildren() << endl;

	BTNode *cu1 = new BTNode ( NULL, NULL, 1234 );
	cout << *cu1 << endl;
	BTNode *cu2 = new BTNode ( NULL, NULL, 2345 );
	cout << *cu2 << endl;

	delete cu1; delete cu2;


	BinaryTree* btaa = new BinaryTree();
	btaa->insert(10);
	cout<<"Inorder   :"; btaa->printInorderTraversal(cout,btaa->head ); cout<<endl;
    cout << "Check Health: " << btaa->checkHealth(); cout << " " << btaa->getrotations()<<endl;
	btaa->insert(3);
	cout<<"Inorder   :"; btaa->printInorderTraversal(cout,btaa->head ); cout<<endl;
    cout << "Check Health: " << btaa->checkHealth(); cout << " " << btaa->getrotations()<<endl;
	btaa->insert(1);
	cout<<"Inorder   :"; btaa->printInorderTraversal(cout,btaa->head ); cout<<endl;
	cout << "Check Health: " << btaa->checkHealth(); cout << " " << btaa->getrotations() << endl;
	btaa->insert(0);
	cout<<"Inorder   :"; btaa->printInorderTraversal(cout,btaa->head ); cout<<endl;
	cout << "Check Health: " << btaa->checkHealth(); cout << " " << btaa->getrotations()<<endl;
	btaa->insert(12);
	for ( int i=250;i>0;i-=2){ btaa->insert(i); }
	cout<<"Inorder   :"; btaa->printInorderTraversal(cout,btaa->head ); cout<<endl;
	cout << "Check Health: " << btaa->checkHealth(); cout << " " << btaa->getrotations()<<endl;

	cout<<"Inorder   :"; btaa->printInorderTraversal(cout,btaa->head ); cout<<endl;
    cout<<"Preorder  :"; btaa->printPreorderTraversal(cout,btaa->head); cout<<endl;
    cout<<"PreorderR :"; btaa->printPreorderTraversalNoRecursion(cout, btaa->head); cout<<endl;
    cout<<"Postorder :"; btaa->printPostorderTraversal(cout,btaa->head); cout<<endl;
    cout << flush;
    cout << "Check Health: " << btaa->checkHealth(); cout << " " << btaa->getrotations() <<endl;

	return 0;
}
