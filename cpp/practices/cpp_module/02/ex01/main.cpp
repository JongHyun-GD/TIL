#include "Fixed.hpp"
#include <iostream>

void print_float_bit(float f) {
	int *p = (int *)&f;
	int bit[32];
	for (int i=0;i<32;++i) {
		bit[i] = (*p) & 1;
		(*p) = (*p) >> 1;
	}
	int cnt =0;
	std::cout << sizeof(float) << std::endl;
	for (int i=31;i>=0;--i) {
		cnt++;
		std::cout << bit[i];
		if (cnt % 8 == 0) std::cout << " ";
	}
	std::cout << std::endl;
}

int main(void) {
	Fixed const c(21.f);
	print_float_bit(21.f);
	std::cout << c << std::endl;

	return 0;
}
