#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
	:Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	:Form(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	setIsSigned(other.getIsSigned());
	_target = other.getTarget();
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const
{
	if (getIsSigned() == false)
		throw ShrubberyCreationForm::UnsignedFormException();
	else if (getExecuteGrade() < bureaucrat.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	else
	{
		std::ofstream fout(_target + "_shrubbery");
		if (fout.fail())
		{
			throw ShrubberyCreationForm::OpenFileException();
			return;
		}
		fout << "          #          \n";
		fout << "         ###         \n";
		fout << "       #######       \n";
		fout << "      #########      \n";
		fout << "    #############    \n";
		fout << "   ###############   \n";
		fout << "  #################  \n";
		fout << " ################### \n";
		fout << "#####################\n";
		fout << "         ###         \n";
		fout << "         #####       \n";
		fout << "         ###         \n";
		fout << "        #####        \n";
		fout << "---------------------\n";
		fout.close();
	}
}

const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return "failed to open file";
}
