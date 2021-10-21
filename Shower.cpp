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

Shower::Shower(const Converter &conv) : convPtr(&conv) {}

Shower::~Shower() {}

