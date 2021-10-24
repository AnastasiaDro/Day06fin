#include <iostream>
#include "Utils.hpp"
#include "Data.hpp"
#include <iomanip>

uintptr_t serialize(Data* dPtr)
{
	uintptr_t uPtr;
	uPtr = reinterpret_cast<uintptr_t>(dPtr);
	return uPtr;
}

Data* deserialize(uintptr_t uPtr)
{
	Data *dPtr;
	dPtr = reinterpret_cast<Data*>(uPtr);
	return dPtr;
}

int main() {
	Data *data1 = new Data("Jimmy", 8);
	Data *data1res;
	Data *data2 = new Data("Jagger", 10);
	Data *data2res;
	uintptr_t p1 = 0;
	uintptr_t p2 = 0;
//	std::cout << std::setbase(16);


	printMsg("-----BEFORE SERIALIZATION-----");
	std::cout << *data1 << std::endl;
	std::cout << *data2 << std::endl;

	std::cout << "uintptr_t p1: " << p1 << std::endl;
	std::cout << "uintptr_t p2: " << p2 << std::endl;

	p1 = serialize(data1);
	p2 = serialize(data2);

	printMsg("\n-----POINTERS AFTER SERIALIZATION-----");

	std::cout << "data1 pointer: " << data1 << std::endl;
	std::cout << "data2 pointer: " << data2 << std::endl;


	std::cout << "uintptr_t p1: " << p1 << std::endl;
	std::cout << "uintptr_t p2: " << p2 << std::endl;

	std::cout << "-----HEXADEMICAL UINTPTRs-----" << std:: endl;

	std::cout << std::setbase(16) << "uintptr_t p1: " << p1 << std::endl;
	std::cout << std::setbase(16) << "uintptr_t p1: " << p2 << std::endl;

	data1res = deserialize(p1);
	data2res = deserialize(p2);

	printMsg("\n-----AFTER DESERIALIZATION-----");

	std::cout << "data1res: " << *data1res << std::endl;
	std::cout << "data2res: "<< *data2res << std::endl;

	std::cout << "data1res pointer: " << data1res << std::endl;
	std::cout << "data3res pointer: " << data2res << std::endl;

	std::cout << "data1 pointer: " << data1 << std::endl;
	std::cout << "data2 pointer: " << data2 << std::endl;

	std::cout << std::setbase(10);

	std::cout << "uintptr_t p1: " << p1 << std::endl;
	std::cout << "uintptr_t p1: " << p2 << std::endl;

	std::cout << "-----HEXADEMICAL UINTPTRs-----" << std:: endl;

	std::cout << std::setbase(16) << "uintptr_t p1: " << p1 << std::endl;
	std::cout << std::setbase(16) << "uintptr_t p1: " << p2 << std::endl;

	delete data1;
	delete data2;

	return 0;
}
