/*
 * token.h
 *
 *  Created on: 13 Jul. 2018
 *      Author: mguppy
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "lexer.h"

enum class TokenType {
	DATA_BOOLEAN,               //[bool/boolean]
	DATA_BYTE,                  //byte
	DATA_SHORT,                 //short
	DATA_INTEGER,               //int
	DATA_FLOATING_INTEGER,      //float
	DATA_LONG,                  //long
	DATA_FLOATING_LONG,         //double

	DATA_VOID,                  //void
	DATA_CLASS,                 //[class name]
	DATA_INITIALIZED_COROUTINE, //routine

	FIELD_DATA,                 //[field name]
	FIELD_METHOD,               //[method name]()
	FIELD_CLASS,                //[class name]

	CLASS_DECLARATION,          //class

	VISIBILITY_ALL,             //public
	VISIBILITY_PACKAGE,         //internal
	VISIBILITY_SUBCLASS,        //protected

	METHOD_RETURN_VALUE,        //return
	METHOD_YIELD_VALUE,         //yield

	COROUTINE_DECLATATION,      //yields
	COROUTINE_INITIALIZE,       //begin
	COROUTINE_CALL,             //seed
	COROUTINE_RETURN,           //harvest

	MEMORY_ALLOCATE,            //new
	MEMORY_DEALLOCATE,          //delete

	END_OF_STATEMENT,           //;

	UNKNOWN
};

class Token {

public:
	TokenType getType();
	char* getValue();

	Token(TokenType, char*);

private:
	TokenType type;
	char* val;
};

#endif /* TOKEN_H_ */
