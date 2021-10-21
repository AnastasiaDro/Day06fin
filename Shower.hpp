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

	const Converter *convPtr;

	void makeIntS();
	void makeDoubleS();
	void makeFloatS();
	void makeCharS();
public:
	Shower(const Converter &conv);
	~Shower();
	void showVals();
};


#endif //SHOWER_HPP
