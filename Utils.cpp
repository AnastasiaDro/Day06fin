//
// Created by Cesar Erebus on 10/19/21.
//

#include "Utils.hpp"

void printMsg(std::string const &msg)
{
	std::cout << msg << std::endl;
}

bool isArgValid(char *s)
{
	int i = 0;
	size_t len = strlen(s);
	if(len == 1)
		return true;
	while(s[i])
	{
		if (!isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
			return false;
		i++;
	}
	return true;
}