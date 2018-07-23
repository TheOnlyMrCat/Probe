/*
 * lexer.cpp
 *
 *  Created on: 26 Jun. 2018
 *      Author: mguppy
 */
 #include <utility>

#include "lexer.h"
#include "util.h"

namespace lor {
	void Lexer::lexString(std::string line) {
		std::vector<std::string> tokens = splitString(std::move(line), " ");

		TokenType carriedToken = nullptr;
		for (std::string token : tokens) {
			TokenType lexedToken;

			bool endOfStatement = false;

			if (carriedToken) {
				auto *lex = new Token(carriedToken, const_cast<char *>(token.c_str()));
				carriedToken = nullptr;
			}

			if (token.back() == ';'){
				endOfStatement = true;
				token.pop_back();
			}

			if (token == "bool" || token == "boolean")  carriedToken = TokenType::DATA_BOOLEAN;
			else if (token == "byte")                   carriedToken = TokenType::DATA_BYTE;
			else if (token == "short")                  carriedToken = TokenType::DATA_SHORT;
			else if (token == "int")                    carriedToken = TokenType::DATA_INTEGER;
			else if (token == "float")                  carriedToken = TokenType::DATA_FLOATING_INTEGER;
			else if (token == "long")                   carriedToken = TokenType::DATA_LONG;
			else if (token == "double")                 carriedToken = TokenType::DATA_FLOATING_LONG;
			else if (token == "routine")                carriedToken = TokenType::DATA_INITIALIZED_COROUTINE;
			else if (token == "void")                   carriedToken = TokenType::DATA_VOID;

			else if (token == "class")                  lexedToken = TokenType::CLASS_DECLARATION;
			else if (token == "yields")                 lexedToken = TokenType::COROUTINE_DECLATATION;

			else if (token == "public")                 lexedToken = TokenType::VISIBILITY_ALL;
			else if (token == "internal")               lexedToken = TokenType::VISIBILITY_PACKAGE;
			else if (token == "protected")              lexedToken = TokenType::VISIBILITY_SUBCLASS;

			else if (token == "return")                 lexedToken = TokenType::METHOD_RETURN_VALUE;
			else if (token == "yield")                  lexedToken = TokenType::METHOD_YIELD_VALUE;

			else if (token == "begin")                  lexedToken = TokenType::COROUTINE_INITIALIZE;
			else if (token == "seed")                   lexedToken = TokenType::COROUTINE_CALL;
			else if (token == "harvest")                lexedToken = TokenType::COROUTINE_RETURN;

			else if (token == "new")                    lexedToken = TokenType::MEMORY_ALLOCATE;
			else if (token == "delete")                 lexedToken = TokenType::MEMORY_DEALLOCATE;

			lexedTokens.push_back(Token(carriedToken ? carriedToken : lexedToken, 0));

			if (endOfStatement) lexedTokens.push_back(Token(TokenType::END_OF_STATEMENT, 0));

			/*switch (token.c_str()) {
				case "bool":
				case "boolean":
					carriedToken = TokenType::DATA_BOOLEAN;
					lexedTokenType = TokenType::DATA_BOOLEAN;
					break;
				case "byte":
					carriedToken = TokenType::DATA_BYTE;
					lexedTokenType = TokenType::DATA_BYTE;
					break;
				case "short":
					carriedToken = TokenType::DATA_SHORT;
					lexedTokenType = TokenType::DATA_SHORT;
					break;
				case "int":
					carriedToken = TokenType::DATA_INTEGER;
					lexedTokenType = TokenType::DATA_INTEGER;
					break;
				case "float":
					carriedToken = TokenType::DATA_FLOATING_INTEGER;
					lexedTokenType = TokenType::DATA_FLOATING_INTEGER;
					break;
				case "long":
					carriedToken = TokenType::DATA_LONG;
					lexedTokenType = TokenType::DATA_LONG;
					break;
				case "double":
					carriedToken = TokenType::DATA_FLOATING_LONG;
					lexedTokenType = TokenType::DATA_FLOATING_LONG;
					break;
				case "void":
					carriedToken = TokenType::DATA_VOID;
					lexedTokenType = TokenType::DATA_VOID;
					break;

				case "class":
					lexedTokenType = TokenType::CLASS_DECLARATION;
					break;
				case "yields":
					lexedTokenType = TokenType::COROUTINE_DECLATATION;
					break;

				case "public":
					lexedTokenType = TokenType::VISIBILITY_ALL;
					break;
				case "internal":
					lexedTokenType = TokenType::VISIBILITY_PACKAGE;
					break;
				case "protected":
					lexedTokenType = TokenType::VISIBILITY_SUBCLASS;
					break;

				case "return":
					lexedTokenType = TokenType::METHOD_RETURN_VALUE;
					break;
				case "yield":
					lexedTokenType = TokenType::METHOD_YIELD_VALUE;
					break;

				case "begin":
					lexedTokenType = TokenType::COROUTINE_INITIALIZE;
					break;
				case "seed":
					lexedTokenType = TokenType::COROUTINE_CALL;
					break;
				case "harvest":
					lexedTokenType = TokenType::COROUTINE_RETURN;
					break;
				case "routine":
					lexedTokenType = TokenType::DATA_INITIALIZED_COROUTINE;
					break;

				case "new":
					lexedTokenType = TokenType::MEMORY_ALLOCATE;
					break;
				case "delete":
					lexedTokenType = TokenType::MEMORY_DEALLOCATE;
					break;
			}*/

		}
	}

	std::vector<Token> Lexer::getTokens() {
		return lexedTokens;
	}
}
