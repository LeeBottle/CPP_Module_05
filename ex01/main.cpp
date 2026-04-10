#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: Form Creation & Insertion Operator ---" << std::endl;
	try {
		Form f1("Tax Return", 50, 25);
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Form Creation with Invalid Grade ---" << std::endl;
	try {
		Form f2("Top Secret", 0, 151);
	} catch (std::exception &e) {
		std::cerr << "Expected Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Successful Signing ---" << std::endl;
	try {
		Bureaucrat boss("High Manager", 20);
		Form f3("Vacation Request", 50, 50);
		
		std::cout << boss << std::endl;
		std::cout << f3 << std::endl;
		
		boss.signForm(f3);
		std::cout << "After signing: " << f3 << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Unexpected Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Failed Signing (Grade too low) ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 120);
		Form f4("Presidential Order", 1, 1);
		
		std::cout << intern << std::endl;
		std::cout << f4 << std::endl;
		
		intern.signForm(f4);
		std::cout << "Final state: " << f4 << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error in main: " << e.what() << std::endl;
	}

	return 0;
}