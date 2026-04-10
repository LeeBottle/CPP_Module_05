#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
	: _name("Default AForm"), _signed(false), _signGrade(150), _executeGrade(150)
{
	//std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	//std::cout << "AForm Designated Constructor called" << std::endl;
	if (_signGrade < 1 || _executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	//std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed), 
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	//std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	//std::cout << "AForm Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm [" << f.getName() << "], signed: ";
	
	if (f.getSigned()) {
		os << "Yes";
	} else {
		os << "No";
	}

	os << ", sign grade required: " << f.getSignGrade()
	<< ", execute grade required: " << f.getExecuteGrade();
	
	return os;
}