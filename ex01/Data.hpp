//
// Created by Cesar Erebus on 10/21/21.
//

#ifndef DAY06_DATA_HPP
#define DAY06_DATA_HPP


#include <string>

class Data {
private:
//ortodox stuff
	Data();
//variables
	std::string	me;
	int			num;
public:
	Data(const std::string &me, int num);
//ortodox stuff
	~Data();
	Data(const Data &orig);
	Data &operator=(const Data &orig);
//getters
	const std::string &getMe() const;
	int getNum() const;
};

std::ostream &operator<<(std::ostream &out, Data data);
#endif //DAY06_DATA_HPP
