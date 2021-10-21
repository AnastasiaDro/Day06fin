//
// Created by Cesar Erebus on 10/19/21.
//

#include <iostream>
#include "Converter.hpp"

Converter::Converter() : _s("noname") {}

Converter::Converter(const std::string &s) : _s(s) {}

Converter::Converter(Converter &orig) : _s(orig._s) {
	*this = orig;
}

Converter::~Converter() {}

Converter &Converter::operator=(const Converter &orig) {
	if(this == &orig)
		return *this;
	this->type = orig.type;
	this->val_chr = orig.val_chr;
	this->val_double = orig.val_double;
	this->val_float = orig.val_float;
	this->val_int = orig.val_int;
	return *this;
}

void Converter::findType() {
	if (this->_s.length() == 1 && !isdigit(this->_s[0]))
		this->type = TYPE_CHAR;
	else if (this->_s.find('f'))
		this->type = TYPE_FLOAT;
	else if (this->_s.find('.'))
		this->type = TYPE_DOUBLE;
	else
		this->type = TYPE_INT;
}

void Converter::setVals() {
	this->stream << this->_s;
	switch (this->type) {
		case TYPE_INT:
			parseInt();
			break;
		case TYPE_FLOAT:
			parseFloat();
			break;
		case TYPE_DOUBLE:
			parseDouble();
			break;
		case TYPE_CHAR:
			parseChar();
			break;
	}

}

void Converter::parseInt() {
	long tmp;
	this->stream >> tmp;
	if (stream.fail() || !isInLimits(tmp))
		this->type = TYPE_INVALID;
	else {
		this->val_int = (int)tmp;
		this->val_chr = static_cast<char>(this->val_int);
		this->val_double = static_cast<double>(this->val_int);
		this->val_float = static_cast<float>(this->val_int);
	}
}

void Converter::parseDouble() {
	char *tmp;
	this->stream >> tmp;
	this->val_double = strtod(tmp, NULL);
	this->val_int = static_cast<int>( this->val_double);
	this->val_chr = static_cast<char>(this->val_double);
	this->val_float = static_cast<float>(this->val_double);
}

void Converter::parseFloat() {
	char *tmp;
	this->stream >> tmp;
	this->val_float = strtof(tmp, NULL);
	this->val_int = static_cast<int>( this->val_float);
	this->val_chr = static_cast<char>(this->val_float);
	this->val_double = static_cast<float>(this->val_float);
}

void Converter::parseChar() {
	char *tmp;
	this->stream >> tmp;
	this->val_chr = *tmp;
	this->stream >> this->val_chr;
	this->val_int = static_cast<int>((unsigned char)this->val_chr);
	this->val_float = static_cast<char>(this->val_chr);
	this->val_double = static_cast<float>(this->val_chr);
}

bool Converter::isInLimits(long l) {
	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		return false;
	return true;
}



void Converter::convert() {
	findType();
	setVals();
}

