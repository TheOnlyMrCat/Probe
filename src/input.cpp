/*
 * imput.cpp
 *
 *  Created on: 13 Jun. 2018
 *      Author: mguppy
 */
#include "input.h";

using namespace std;

int main() {
	getInput();
	int code = parse();
	return code == 0 ? interpret() : code;
}

void getInput() {
	string mainClassPath;
	cin >> input;
	cin >> mainClassPath;

}

int parse() {
	return 0;
}

int interpret() {
	return 0;
}
