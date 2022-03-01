#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public virtual Animal {
public:
	Dog();
	Dog(Dog &other);
	~Dog();
	Dog &operator=(Dog &other);

	void makeSound() const;
	Brain *brain;
};

#endif
