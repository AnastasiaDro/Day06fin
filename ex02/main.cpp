#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

class Base
{
public:
	virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base * generate()
{
	int mRand = rand() % 3;
	switch (mRand) {
		case 0:
			return new A;
			break;
		case 1:
			return new B;
			break;
		case 2:
			return new C;
			break;
		default:
			return new Base;
	}
}

int main() {
	srand( time(0) );
	Base *one = generate();

	A *a;
	B *b;
	C *c;

//returns NULL if casting is impossible
	a = dynamic_cast<A*>(one);
	b = dynamic_cast<B*>(one);
	c = dynamic_cast<C*>(one);

	if (a)
		std::cout << "this is a" << std::endl;
	if (b)
		std::cout << "this is b" << std::endl;
	if (c)
		std::cout << "this is c" << std::endl;
	delete one;
}
