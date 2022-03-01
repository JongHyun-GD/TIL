#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		const std::string &getType();
		void setType(const std::string &newType);
	private:
		std::string type;
};

#endif
