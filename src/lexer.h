/*
 * lexer.h
 *
 *  Created on: 26 Jun. 2018
 *      Author: mguppy
 */

#ifndef LEXER_H_
#define LEXER_H_

#include <string>
#include <vector>
#include "token.h"

namespace lor {
	class Lexer {
	public:
		void lexString(std::string line);
		std::vector<Token> getTokens();

	private:
		std::vector<Token> lexedTokens;
	};
}

#endif /* LEXER_H_ */
