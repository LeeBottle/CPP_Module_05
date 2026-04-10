#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <string>
#include <iostream>

class AForm;

class Intern
{

public:
	Intern( void );
	virtual ~Intern( void );
	Intern( const Intern& other );
	Intern& operator=( const Intern& other );

	AForm*	makeForm(std::string name, std::string target);
};

#endif
