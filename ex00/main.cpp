#include <iostream>
#include "Utils.hpp"
#include <iomanip>

int main(int argc, char **argv) {

	double d;
	int i;
	char c;
	float f;
	double rem;

	if (argc != 2)
	{
		printMsg("Invalid arg!");
		exit(1);
	}
	d = strtod(argv[1], NULL);
	i = static_cast<int>(d);
	c = static_cast<char>(d);
	f = static_cast<float>(d);

	rem = d - static_cast<double>(i);

	std::cout << std::setprecision((int)strlen(argv[1]));

	printChr(c, d);
	printInt(i, d);
	printDouble(d, rem);
	printFloat(f, rem);

	return 0;
}
