#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
	: _name("Default Form"), _signed(false), _signGrade(150), _executeGrade(150)
{
	//std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	//std::cout << "Form Designated Constructor called" << std::endl;
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	//std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), 
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	//std::cout << "Form Copy Constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	//std::cout << "Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form [" << f.getName() << "], signed: ";
	
	if (f.getSigned()) {
		os << "Yes";
	} else {
		os << "No";
	}

	os << ", sign grade required: " << f.getSignGrade()
	<< ", execute grade required: " << f.getExecuteGrade();
	
	return os;
}