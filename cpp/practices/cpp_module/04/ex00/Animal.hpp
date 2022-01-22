#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
public:
	Animal();
	Animal(Animal &other);
	~Animal();
	Animal &operator=(Animal &other);

	std::string getType() const;
	virtual void makeSound() const;
protected:
	std::string type;
};

#endif
