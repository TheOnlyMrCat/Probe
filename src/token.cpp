/*
 * token.cpp
 *
 *  Created on: 22 Jul. 2018
 *      Author: mguppy
 */

#include "token.h"

TokenType Token::getType() {
	return type;
}

char* Token::getValue() {
	return val;
}

Token::Token(TokenType tokenType, char* value) {
	type = tokenType;
	val = value;
}
