/*
 * util.cpp
 *
 *  Created on: 26 Jun. 2018
 *      Author: mguppy
 */

#include <vector>
#include "util.h"

using namespace std;

vector<string> splitString(string text, char regex) {
	vector<string> tokens;
	size_t start = 0, end = 0;
	while ((end = text.find(regex, start)) != string::npos) {
	  tokens.push_back(text.substr(start, end - start));
	  start = end + 1;
	}
	tokens.push_back(text.substr(start));
	return tokens;
}
