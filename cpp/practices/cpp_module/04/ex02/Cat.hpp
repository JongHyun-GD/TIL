#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public virtual Animal {
public:
	Cat();
	Cat(Cat &other);
	~Cat();
	Cat &operator=(Cat &other);

	void makeSound() const;
	Brain *brain;
};

#endif
