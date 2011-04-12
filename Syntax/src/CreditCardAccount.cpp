/*
 * CreditCardAccount.cpp
 *
 *  Created on: Oct 18, 2010
 *      Author: aurelio
 */

#include "CreditCardAccount.h"

namespace syntax {


CreditCardAccount::~CreditCardAccount() {
	// TODO Auto-generated destructor stub
}

bool CreditCardAccount::Bill( const int amount ) {
	if ( this->balance - amount < 0 ) {
		return false;
	}
	this->balance -= amount;
	return true;
}


}
