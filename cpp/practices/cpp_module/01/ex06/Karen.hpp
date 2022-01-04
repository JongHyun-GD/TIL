#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>
# include <iostream>

class Karen
{
	public:
		Karen(std::string filter);
		void complain(std::string level);
		static void (Karen::*funcs[4])();
		static std::string levels[4];

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		int filter_level;
};


#endif
