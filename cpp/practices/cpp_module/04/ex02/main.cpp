#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\033[1;31m === Initializing === \033[0m\n";
	int arr_size = 10;
	Animal *arr[arr_size];
	for (int i=0; i<arr_size; ++i) {
		std::cout << i << ": ";
		if (i < arr_size/2) arr[i] = new Dog();
		else arr[i] = new Cat();
	}
	for (int i=0; i<arr_size; ++i) {
		std::cout << i << ": ";
		delete arr[i];
	}

	std::cout << "\033[1;31m === Deep copy === \033[0m\n";
	Dog *i = new Dog();
	i->brain->ideas[0] = "Hello, ";
	i->brain->ideas[1] = "World!";
	Dog *j = new Dog(*i);
	delete i;
	std::cout << j->brain->ideas[0] << j->brain->ideas[1] << std::endl;
	delete j;

	//std::cout << "\033[1;31m === Animal Initialization ===\033[0m\n";
	//Animal animal;
}
