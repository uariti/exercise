/*
 * CreditCardAccount.h
 *
 *  Created on: Oct 18, 2010
 *      Author: aurelio
 */

#ifndef CREDITCARDACCOUNT_H_
#define CREDITCARDACCOUNT_H_

#include "Accounts.h"

namespace syntax {

class CreditCardAccount: public syntax::Accounts {
public:
	virtual bool Bill( const int amount );
public:
	CreditCardAccount( const std::string & name, const int balance )
	   : Accounts(name, balance) {};
	virtual ~CreditCardAccount();
};

}

#endif /* CREDITCARDACCOUNT_H_ */
