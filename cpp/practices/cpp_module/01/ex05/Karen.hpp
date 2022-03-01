#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>
# include <iostream>

class Karen
{
	public:
		Karen();
		void complain(std::string level);

		typedef struct KarenComplain
		{
			std::string str;
			void (Karen::*func)();
		}			t_KarenComplain;

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		t_KarenComplain tc[4];
};

#endif
