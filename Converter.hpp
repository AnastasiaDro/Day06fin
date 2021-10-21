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

	std::string chrS;
	std::string intS;
	std::string floatS;
	std::string doubleS;

	void parseInt();
	void parseDouble();
	void parseFloat();
	void parseChar();

	void findType(); //ищет тип
	void setVals();

	bool isCharLimits(long tmp);

	bool isIntLimits(long l);
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

//getters
	int getValInt() const;
	char getValChr() const;
	float getValFloat() const;
	double getValDouble() const;
	int getType() const;

	void convert();


	 //показывает значение

};


#endif //DAY06_CONVERTER_HPP
