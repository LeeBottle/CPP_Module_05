#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern someRandomIntern;
	Bureaucrat boss("The Boss", 1);
	AForm* rrf;

	std::cout << "--- Test 1: Intern creates a valid form ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	if (rrf) {
		std::cout << *rrf << std::endl;
		
		boss.signForm(*rrf);
		boss.executeForm(*rrf);

		delete rrf;
	}

	std::cout << "\n--- Test 2: Intern creates another valid form ---" << std::endl;
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	
	if (scf) {
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	std::cout << "\n--- Test 3: Intern tries to create an unknown form ---" << std::endl;
	AForm* unknown;
	unknown = someRandomIntern.makeForm("coffee making form", "Kitchen");

	if (!unknown) {
		std::cout << "Intern failed to create the form as expected." << std::endl;
	}

	return 0;
}