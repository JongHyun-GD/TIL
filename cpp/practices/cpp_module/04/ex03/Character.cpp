#include "Character.hpp"

Character::Character()
	: _name(""), _invenSize(0)
{
	for (int i=0; i<MAX_INVEN_SIZE; ++i)
		_inven[i] = NULL;
	std::cout << "Character is created.\n";
}

Character::Character(std::string name)
	: _name(name), _invenSize(0)
{
	for (int i=0; i<MAX_INVEN_SIZE; ++i)
		_inven[i] = NULL;
	std::cout << "Character " << name << " is created.\n";
}

Character::Character(Character &other)
	: _name(other.getName()), _invenSize(other._invenSize)
{
	for (int i = 0; i < MAX_INVEN_SIZE; ++i)
	{
		if (other._inven[i] != NULL)
			_inven[i] = other._inven[i]->clone();
		else
			_inven[i] = NULL;
	}

	std::cout << "Character " << _name << " is created.\n";
}

Character::~Character()
{
	for (int i=0; i < MAX_INVEN_SIZE; ++i)
		if (_inven[i] != NULL)
			delete _inven[i];
	std::cout << "Character " << _name << " died.\n";
}

Character &Character::operator=(Character &other)
{
	_name = other._name;
	_invenSize = other._invenSize;

	for (int i = 0; i < MAX_INVEN_SIZE; ++i)
	{
		if (other._inven[i] != NULL)
			_inven[i] = other._inven[i]->clone();
		else
			_inven[i] = NULL;
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria *m)
{
	if (m == NULL)
	{
		std::cout << "Character can not equip NULL Materia.\n";
		return;
	}

	if (this->_invenSize < this->MAX_INVEN_SIZE)
	{
		for (int i = 0; i < MAX_INVEN_SIZE; ++i)
		{
			if (_inven[i] == NULL)
			{
				_inven[i] = m;
				std::cout << _name << " equipped " << m->getType() << " on slot " << i << ".\n";
				_invenSize++;
				break;
			}
		}
	}
	else
		std::cout << "Can not equip materia. Inventory is full.\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_INVEN_SIZE && _inven[idx] != NULL)
	{
		std::cout << _name << " unequipped " << _inven[idx]->getType() << ".\n";
		_invenSize--;
		_inven[idx] = NULL;
	}
	else
		std::cout << "Can not unequip materia. There is no materia.\n";
}
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < MAX_INVEN_SIZE && _inven[idx] != NULL)
	{
		_inven[idx]->use(target);
	}
	else
		std::cout << "Can not use materia. There is no materia.\n";
}

AMateria *Character::getMateriaFromInventory(int idx)
{
	return _inven[idx];
}
