#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal &other);
	~WrongAnimal();
	WrongAnimal &operator=(WrongAnimal &other);

	std::string getType() const;
	void makeSound() const;
protected:
	std::string type;
};

#endif
