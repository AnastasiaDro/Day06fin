#include <iostream>
#include "Utils.hpp"
#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		printMsg("invalid arg");
		return (1); ////Погуглить коды ошибок
	}
	Converter converter(argv[1]);
	if (!converter.isArgValid())
	{
		printMsg("invalid arg");
		return (1);
	}

	converter.convert();
	converter.showVals();
	return 0;
}
