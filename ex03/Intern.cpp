#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	//std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::~Intern(void)
{
	//std::cout << "Intern Destructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	//std::cout << "Intern Copy Constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	//std::cout << "Intern Copy Assignment Operator called" << std::endl;
	(void)other;
	return *this;
}


AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	int i = 0;
	while (i < 3 && formNames[i] != name)
		i++;

	AForm* result = NULL;
	switch (i)
	{
		case 0:
			result = new PresidentialPardonForm(target);
			break;
		case 1:
			result = result = new RobotomyRequestForm(target);
			break;
		case 2:
			result = new ShrubberyCreationForm(target);
			break;
		default:
			std::cout << "Error: Form name '" << name << "' does not exist." << std::endl;
			return NULL;
	}
	
	std::cout << "Intern creates " << name << std::endl;
	return result;
}