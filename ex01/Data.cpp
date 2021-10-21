//
// Created by Cesar Erebus on 10/21/21.
//

#include <iostream>
#include "Data.hpp"

Data::Data() {}

Data::Data(const std::string &me, int num) : me(me), num(num){}

Data::~Data() {}

Data::Data(const Data &orig) {
	*this = orig;
}

const std::string &Data::getMe() const {
	return me;
}

int Data::getNum() const {
	return num;
}

Data &Data::operator=(const Data &orig) {
	if(this == &orig)
		return *this;
	this->me = orig.me;
	this->num = orig.num;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Data data)
{
	std::cout	<< "Data: Name :"
				<< data.getMe()
				<< " age: " << data.getNum();
	return out;
}






