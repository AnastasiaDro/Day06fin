#include <iostream>
#include "Utils.hpp"
#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2 && !isArgValid(argv[1]))
	{
		printMsg("invalid arg");
		return (1); ////Погуглить коды ошибок
	}
	Converter converter(argv[1]);
	converter.convert();
	//converter.showVals();
	return 0;
}
