#include "Base.hpp"

Base::~Base()
{
}

Base* generate(void)
{
	srand(time(NULL));
	switch (rand() % 3) {
		case 0:
			std::cout << "A is created.\n";
			return new A();
			break;
		case 1:
			std::cout << "B is created.\n";
			return new B();
			break;
		case 2:
			std::cout << "C is created.\n";
			return new C();
			break;
		default:
			std::cout << "A is created.\n";
			return new A();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Ptr Answer: A!\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Ptr Answer: B!\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Ptr Answer: C!\n";
}

void identify(Base& p)
{
	try {
		A& ptr = dynamic_cast<A&>(p);
		std::cout << "Ref Answer: A!\n";
		(void)ptr;
	}
	catch (std::exception &e) {}
	try {
		B& ptr = dynamic_cast<B&>(p);
		std::cout << "Ref Answer: B!\n";
		(void)ptr;
	}
	catch (std::exception &e) {}
	try {
		C& ptr = dynamic_cast<C&>(p);
		std::cout << "Ref Answer: C!\n";
		(void)ptr;
	}
	catch (std::exception &e) {}

}
