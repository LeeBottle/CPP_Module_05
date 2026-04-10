#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "--- Test 1: Normal Construction & Insertion Operator ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		
		bob.incrementGrade(); // 2 -> 1
		std::cout << "After increment: " << bob << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Grade Too High (Constructor) ---" << std::endl;
	try {
		Bureaucrat boss("The King", 0); // 너무 높은 등급 (1미만)
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Grade Too Low (Constructor) ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 151); // 너무 낮은 등급 (150초과)
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Increment beyond limits ---" << std::endl;
	try {
		Bureaucrat high("High Flyer", 1);
		std::cout << high << std::endl;
		high.incrementGrade(); // 1에서 더 올리려고 시도 (오류 발생 지점)
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Decrement beyond limits ---" << std::endl;
	try {
		Bureaucrat low("Slacker", 150);
		std::cout << low << std::endl;
		low.decrementGrade(); // 150에서 더 내리려고 시도 (오류 발생 지점)
	} catch (std::exception &e) {
		std::cerr << "Expected error: " << e.what() << std::endl;
	}

	return 0;
}