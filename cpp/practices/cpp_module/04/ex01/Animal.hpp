#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	std::string getType() const;
	virtual void makeSound() const;
protected:
	std::string type;
private:
	Animal(Animal &other);
	Animal &operator=(Animal &other);
};

#endif
