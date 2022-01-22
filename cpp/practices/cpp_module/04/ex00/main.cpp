#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	//const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	//meta->makeSound();

	// Wrong inheritance test
	const WrongAnimal *wrong_i = new WrongCat();
	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound();
}
