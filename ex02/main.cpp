#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	// 랜덤 시드 설정 (Robotomy의 50% 확률 테스트를 위해)
	std::srand(std::time(NULL));

	std::cout << "===== Bureaucrat Recruitment =====" << std::endl;
	Bureaucrat president("President", 1);
	Bureaucrat manager("Manager", 40);
	Bureaucrat intern("Intern", 146);

	std::cout << president << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;

	std::cout << "\n===== Test 1: ShrubberyCreationForm =====" << std::endl;
	{
		// 요구 등급: 서명 145, 실행 137
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;

		intern.executeForm(shrub);	// 실패: 서명 안 됨
		intern.signForm(shrub);	   // 실패: 등급 낮음 (146 < 145)
		
		manager.signForm(shrub);	  // 성공
		intern.executeForm(shrub);	// 실패: 실행 등급 낮음 (146 < 137)
		manager.executeForm(shrub);   // 성공: home_shrubbery 파일 생성 확인
	}

	std::cout << "\n===== Test 2: RobotomyRequestForm =====" << std::endl;
	{
		// 요구 등급: 서명 72, 실행 45
		RobotomyRequestForm robot("Bender");
		
		manager.signForm(robot);	  // 성공 (40 <= 72)
		manager.executeForm(robot);   // 성공 (40 <= 45), 50% 확률 메시지 확인
		manager.executeForm(robot);   // 한 번 더 실행해서 확률 확인
		manager.executeForm(robot);
	}

	std::cout << "\n===== Test 3: PresidentialPardonForm =====" << std::endl;
	{
		// 요구 등급: 서명 25, 실행 5
		PresidentialPardonForm pardon("Criminal");

		manager.signForm(pardon);	 // 실패: 서명 등급 부족 (40 < 25)
		president.signForm(pardon);   // 성공
		manager.executeForm(pardon);  // 실패: 실행 등급 부족 (40 < 5)
		president.executeForm(pardon);// 성공
	}

	std::cout << "\n===== Test 4: Abstract Class Check =====" << std::endl;
	// AForm test = AForm("Abstract", 10, 10); 
	// 주석을 해제하면 컴파일 에러가 나야 합니다. (추상 클래스이므로 인스턴스화 불가)

	return 0;
}