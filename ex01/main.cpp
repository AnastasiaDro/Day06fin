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

	printMsg("-----BEFORE SERIALIZATION-----");
	std::cout << *data1 << std::endl;
	std::cout << *data2 << std::endl;

	uintptr_t p1 = serialize(data1);
	uintptr_t p2 = serialize(data2);
	data1res = deserialize(p1);
	data2res = deserialize(p2);

	printMsg("\n-----AFTER DESERIALIZATION-----");

	std::cout << *data1res << std::endl;
	std::cout << *data2res << std::endl;

	delete data1;
	delete data2;

	return 0;
}
