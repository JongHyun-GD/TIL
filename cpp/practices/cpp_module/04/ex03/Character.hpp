#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	Character();

	std::string _name;
	static const int MAX_INVEN_SIZE = 4;
	int _invenSize;
	AMateria *_inven[4];

public:
	Character(std::string name);
	Character(Character &other);
	Character &operator=(Character &other);
	~Character();

	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	AMateria *getMateriaFromInventory(int idx);
	std::string const &getName() const;
};

#endif
