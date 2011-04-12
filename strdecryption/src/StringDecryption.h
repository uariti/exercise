/*
 * StringDecryption.h
 *
 *  Created on: Aug 31, 2010
 *      Author: aurelio
 */

#ifndef STRINGDECRYPTION_H_
#define STRINGDECRYPTION_H_

#include <string>

namespace decryption {

class StringDecryption {
protected:
	static const long MODULO = 1000000009;
public:
	StringDecryption();
	virtual ~StringDecryption();

	int decrypt ( std::string& code );
};

}

#endif /* STRINGDECRYPTION_H_ */
