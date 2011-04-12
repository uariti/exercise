//============================================================================
// Name        : Syntax.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CreditCardAccount.h"
using namespace std;
using namespace syntax;

int main() {
	cout << "O imundo" << endl; // prints O imundo

	Accounts *a = new CreditCardAccount("marco CC", 100);
	cout << a->getName() << " has " << a->getBalance() << endl;
	return 0;
}
