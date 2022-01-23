#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *dog1 = new Dog();
	const Animal *cat1 = new Cat();
	std::cout << dog1->getType() << " " << std::endl;
	std::cout << cat1->getType() << " " << std::endl;
	cat1->makeSound(); // will output the cat sound!
	dog1->makeSound();

	// Wrong inheritance test
	const WrongAnimal *wrong_i = new WrongCat();
	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound();
}
