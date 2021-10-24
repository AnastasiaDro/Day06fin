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

void identify(Base* p)
{
	A *a;
	B *b;
	C *c;

//dynamic_cast returns NULL if casting is impossible
	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "this is A" << std::endl;
	if (b)
		std::cout << "this is B" << std::endl;
	if (c)
		std::cout << "this is C" << std::endl;
}

void identify(Base& p)
{
	A a;
	B b;
	C c;

	try {
		a = dynamic_cast<A &>(p);
		std::cout << "this is A" << std::endl;
	} catch (std::bad_cast &exception) { }
	try {
		b = dynamic_cast<B &>(p);
		std::cout << "this is B" << std::endl;
	} catch (std::bad_cast &exception) { }
	try {
		c = dynamic_cast<C &>(p);
		std::cout << "this is C" << std::endl;
	} catch (std::bad_cast &exception) { }
}

int main() {
	srand( time(0) );
	Base *one = generate();

	//void identify(Base* p)
	identify(one);

	//void identify(Base& p)
	identify(*one);

	delete one;
}
