#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		int add();
		int search();
	private:
		const static int MAX_SIZE = 8;
		int size;
		Contact *contacts;
};
