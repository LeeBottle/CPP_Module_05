#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{

private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_executeGrade;

public:
	AForm( void );
	AForm(const std::string name, int signGrade, int executeGrade);
	virtual ~AForm( void );
	AForm( const AForm& other );
	AForm& operator=( const AForm& other );
	

	std::string getName()const;
	bool		getSigned()const;
	int			getSignGrade()const;
	int			getExecuteGrade()const;

	void		beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	//추가사항
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif