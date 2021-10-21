//
// Created by Cesar Erebus on 10/21/21.
//

#ifndef SHOWER_HPP
#define SHOWER_HPP


#include <string>
#include "Converter.hpp"

class Shower {
private:
	Shower();
	std::string chrS;
	std::string intS;
	std::string floatS;
	std::string doubleS;

	void makeIntS();
	void makeDoubleS();
	void makeFloatS();
	void makeCharS(char c);

	void madeStrings(const Converter &converter);
	enum Type {
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_INVALID
	};
public:
	Shower(const Converter &conv);
	Shower(Shower &orig);
	~Shower();
	Shower &operator=(const Shower &orig);

	void showVals();
};


#endif //SHOWER_HPP
