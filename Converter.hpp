//
// Created by Cesar Erebus on 10/19/21.
//

#ifndef CONVERTER_HPP
#define CONVERTER_HPP


#include <string>
#include <sstream>

class Converter {
private:
	Converter();
	const std::string _s;

	int val_int;
	char val_chr;
	float val_float;
	double val_double;
	std::stringstream stream;
	int type;

	std::string intS;
	std::string doubleD;
	std::string floatF;
	std::string chrS;


	enum Type {
		TYPE_CHAR,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_INVALID
	};

public:
	Converter(const std::string &s);
	Converter(Converter &orig);
	~Converter();
	Converter &operator=(const Converter &orig);

	void findType(); //ищет тип

	void setVals();

	void parseInt();
	void parseDouble();
	void parseFloat();
	void parseChar();

	bool isInLimits(long l);
	void showVals(); //показывает значение
};


#endif //DAY06_CONVERTER_HPP
