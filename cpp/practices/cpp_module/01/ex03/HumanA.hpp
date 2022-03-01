#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack();
		void setWeapon(const Weapon& newWeapon);
	private:
		std::string name;
		Weapon &weapon;
};

#endif
