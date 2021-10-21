//
// Created by Cesar Erebus on 10/21/21.
//

#include <iostream>
#include "Shower.hpp"



Shower::Shower() {}



void Shower::showVals() {
	std::cout << this->chrS << "\n"
			  << this->intS << "\n"
			  << this->floatS << "f" << "\n"
			  << this->doubleS
			  << std::endl;
}

Shower::Shower(const Converter &conv) {
	madeStrings(conv);
}

Shower::~Shower() {}

void Shower::makeIntS() {

}

void Shower::makeDoubleS() {

}

void Shower::makeFloatS() {

}

void Shower::makeCharS(char c) {
	//if ()
}

void Shower::madeStrings(const Converter &conv) {

	this->makeCharS(conv.getValChr());
	this->makeIntS();
	this->makeDoubleS();
	this->makeFloatS();
}

Shower &Shower::operator=(const Shower &orig) {
	if(this == &orig)
		return *this;
	this->chrS = orig.chrS;
	this->intS = orig.intS;
	this->doubleS = orig.doubleS;
	this->floatS = orig.floatS;
	return (*this);
}

Shower::Shower(Shower &orig) {
	*this = orig;
}

