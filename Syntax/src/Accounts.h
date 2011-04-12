/*
 * Accounts.h
 *
 *  Created on: Oct 18, 2010
 *      Author: aurelio
 */

#ifndef ACCOUNTS_H_
#define ACCOUNTS_H_

#include <string>

namespace syntax {

class Accounts {
private:
	std::string name;
protected:
	int balance;
public:
	virtual bool Bill( const int amount ) = 0;
public:
	virtual ~Accounts();
    int getBalance() const
    {
        return balance;
    }

    std::string getName() const
    {
        return name;
    }

    void setBalance(int balance)
    {
        this->balance = balance;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    Accounts( const std::string & name, const int balance) :
		name(name), balance(balance) {};
};

}

#endif /* ACCOUNTS_H_ */
