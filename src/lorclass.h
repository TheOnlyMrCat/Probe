/*
 * lorclass.h
 *
 *  Created on: 13 Jun. 2018
 *      Author: mguppy
 */

#ifndef LORCLASS_H_
#define LORCLASS_H_

#include <map>

using namespace std;

class lorClass {

	public:
		const string name;

};

class lorMethod {

	public:
		const lorClass returnType;
};

class lorObject {

	public:
		const lorClass type;
		std::map::map variables = std::map<lorObject, string>();
};

lorClass generateClass(std::string in);

#endif /* LORCLASS_H_ */
