#include <iostream>
#include "Utils.hpp"
#include <iomanip>
#include <cmath>
#include <sstream>


int main(int argc, char **argv) {

	double	d;
	int		i;
	char	c;
	float	f;
	double	rem;
	double	tmp;

	std::string avstr = argv[1];

	if (!checkArg(argc, argv[1]))
	{
		printMsg("Invalid arg!");
		exit(1);
	}

	d = strtod(argv[1], NULL);
	rem = modf(d, &tmp);
	if(strlen(argv[1]) == 1 && !std::isdigit(*(argv[1])))
	{
		c = *(argv[1]);
		i = static_cast<unsigned char>(c);
		d = static_cast<double>(c);
		f = static_cast<float>(c);
	}
	else
	{
		std::cout << std::setprecision((int)strlen(argv[1]));
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
	}
	printChr(c, d);
	printInt(i, d);
	printDouble(d, rem);
	printFloat(f, rem);

	return 0;
}
