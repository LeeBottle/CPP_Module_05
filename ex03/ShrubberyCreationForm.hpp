#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	virtual void execute(Bureaucrat const & executor) const;
	const std::string& getTarget() const;
	
};

#endif