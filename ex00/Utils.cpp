//
// Created by Cesar Erebus on 10/19/21.
//

#include <sstream>
#include <iomanip>
#include "Utils.hpp"

void printMsg(std::string const &msg)
{
	std::cout << msg << std::endl;
}

void printChr(char c, double d)
{
	double cmin = 0;
	double cmax = 127;

	if (d < cmin || d > cmax  || getStringFromDouble(d) == "nan")
	{
		printMsg("char: impossible");
		return;
	}
	if(c < 33 || c > 126)
	{
		printMsg("char: Non displayable");
		return;
	}
	std::cout << "char: " << c << std::endl;
}

void printInt(int i, double d)
{
	double min = INT_MIN;
	double max = INT_MAX;

	if (d < min || d > max || getStringFromDouble(d) == "nan")
		printMsg("int: impossible");
	else
		std::cout << "int: " << i << std::endl;
}

void printDouble(double d, double rem)
{
	double zero = 0;

	std::cout << "double: " << d;
	if (rem == zero && d != std::numeric_limits<double>::infinity() && d != -std::numeric_limits<double>::infinity())
		std::cout << ".0";
	std::cout << std::endl;
}

void printFloat(float f, double rem)
{
	double zero = 0;
	std::cout << "float: " << f;
	if (rem == zero && f != std::numeric_limits<float>::infinity() && f != -std::numeric_limits<float>::infinity())
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

std::string getStringFromDouble(double d)
{
	std::stringstream ss;
	ss << d;
	std::string tmp;
	ss >> tmp;
	return tmp;
}
bool checkArg(char *str)
{
	if(!strcmp(str, "nan") || !strcmp(str, "nanf") || !strcmp(str, "inf") || !strcmp(str, "inff") \
			|| !strcmp(str, "+inf") || !strcmp(str, "+inff") || !strcmp(str, "-inf") || !strcmp(str, "-inff"))
		return true;
	int i = 0;
	if(str[i] == '+' || str[i] == '-')
		i++;
	if (!std::isdigit(str[i]))
		return false;
	while(str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while(str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] == 'f')
		i++;
	if (str[i])
		return false;
	return true;
}
