//
// Created by Cesar Erebus on 10/19/21.
//

#include <iostream>
#include "Converter.hpp"

Converter::Converter() : _s("noname") {}

Converter::Converter(const std::string &s) : _s(s) {
}

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
	this->chrS = orig.chrS;
	return *this;
}

////done
void Converter::findType() {
	if (this->_s.length() == 1 && !isdigit(this->_s[0]))
	{
		this->type = TYPE_CHAR;
		return;
	}
	else if (this->_s.find('f') < 0) {
		this->type = TYPE_FLOAT;
		return;
	}
	else if (this->_s.find('.') < 0) {
		this->type = TYPE_DOUBLE;
		return;
	}
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
	if (stream.fail() || !isIntLimits(tmp))
	{
		this->intS = "impossible";
		this->chrS= "impossible";
	}
	else
	{
		this->val_int = (int)tmp;
		if(isCharLimits(tmp))
			this->val_chr = static_cast<char>(this->val_int);
		this->val_double = static_cast<double>(this->val_int);
		this->val_float = static_cast<float>(this->val_int);
	}
}

void Converter::parseDouble() {
	char *tmp;
	this->stream >> tmp;
	this->val_double = strtod(tmp, NULL);
	long tmp_long = static_cast<long>(this->val_double);
	if(isIntLimits(tmp_long))
		this->val_int = static_cast<int>( this->val_double);
	if (isCharLimits(tmp_long))
		this->val_chr = static_cast<char>(this->val_double);

	this->val_float = static_cast<float>(this->val_double);
}

void Converter::parseFloat() {
	std::string tmp;
	this->stream >> tmp;
	this->val_float = strtof(tmp.c_str(), NULL);
	this->val_int = static_cast<int>( this->val_float);
	this->val_chr = static_cast<char>(this->val_float);
	this->val_double = static_cast<float>(this->val_float);
}

////done
void Converter::parseChar() {
	this->stream >> val_chr;
	this->stream >> this->val_chr;
	this->val_int = static_cast<int>((unsigned char)this->val_chr);
	this->val_float = static_cast<char>(this->val_chr);
	this->val_double = static_cast<float>(this->val_chr);
}

////done
bool Converter::isIntLimits(long l) {
	if (l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
	{
		this->intS = "impossible";
		return false;
	}
	return true;
}

void Converter::convert() {
	if (this->isNan)
	{
		this->chrS = "impossible";
		this->intS = "impossible";
		this->doubleS = sign + "nan";
		this->floatS = sign + "nanf";
		return;
	}
	findType();
	setVals();
}

int Converter::getValInt() const {
	return val_int;
}

char Converter::getValChr() const {
	return val_chr;
}

float Converter::getValFloat() const {
	return val_float;
}

double Converter::getValDouble() const {
	return val_double;
}

int Converter::getType() const {
	return type;
}

bool Converter::isCharLimits(long tmp) {
	if (tmp < 0 || tmp > 127)
	{
		this->chrS = "impossible";
		return false;
	}
	if (tmp < 33  || tmp > 126)
	{
		this->chrS = "Non displayable";
		return false;
	}
	return true;
}

bool Converter::isArgValid() {
	int i = 0;
	int flagDot = 0;
	int flagF = 0;
	long len = this->_s.length();
	if(len == 1)
		return true;
	if (this->_s[i] == '+' || this->_s[i] == '-')
		i++;
	if((this->_s == "nan") || (this->_s == "nanf"))
	{
		this->isNan = true;
		return true;
	}
	while(this->_s[i])
	{
		if (!isdigit(this->_s[i]))
		{
			if(this->_s[i] != '.' && this->_s[i] != 'f')
				return false;
			this->_s[i] == '.' ? flagDot++ : flagF++;
			if (flagF > 1 || flagDot > 1)
				return false;
		}
		i++;
	}
	return true;
}

void Converter::showVals() {
	std::cout << this->chrS << "\n"
			  << this->intS << "\n"
			  << this->floatS << "f" << "\n"
			  << this->doubleS
			  << std::endl;
}

