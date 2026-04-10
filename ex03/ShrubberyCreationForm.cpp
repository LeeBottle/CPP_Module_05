#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned()) {
		throw AForm::NotSignedException();
	}

	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::GradeTooLowException();
	}

	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create file." << std::endl;
		return;
	}

	outfile << "                                                                            " << std::endl;
	outfile << "                                             :=++: . .==-.                  " << std::endl;
	outfile << "                                           :=****+--*++*++=.                " << std::endl;
	outfile << "                                             ==.-****++++++=.-=+:           " << std::endl;
	outfile << "                                             +++*****++**=+*+*++*:          " << std::endl;
	outfile << "                                     .-=+-  -#***####**#*+=**+++-::==+=++   " << std::endl;
	outfile << "                                    *+**+***#**#*####++#+*+=++==+==**+*=*+= " << std::endl;
	outfile << "                                  :+****++++++##########****+++==+++#+===+==+=:. " << std::endl;
	outfile << "                     :=*****+++ ==:*#####**+*++##*+**#*###*##*++=++**=+++++=+=  " << std::endl;
	outfile << "                      .+**##****+*+*####%##**+++++*####**##***+++**=**+*+*+**+= " << std::endl;
	outfile << "                     **=+*###%##%###%%#+++##*#*+****##########*+++=#+**+=+:     " << std::endl;
	outfile << "              -- +*++.  +*+###%#####**+*=+=+#***=**#***##%######+**#+***++- .     .. " << std::endl;
	outfile << "            .-*+#*%#*- ..+*######%#***#**+++++=++++=+*++*########**=*+=+*+*=++=+=.-: " << std::endl;
	outfile << "             ...:*#*.      =*####%#%%####+*=+==##+==-=+##**###**++*+===+=*++++++*=+*= " << std::endl;
	outfile << "           =*+++#++*-  . .=**##%######%##*#*++=*#***+*+#**+####**+===+=====+=+=#++  ==. " << std::endl;
	outfile << "          :-      ..-+==#######*#*####%#***###*####*###**+++#####%##**+=-****+++++.-. " << std::endl;
	outfile << "                  .+*+###%%%%#####==+**#**#%#*#####***=*++=*=++#*++#+==+*+**+-=+:. " << std::endl;
	outfile << "                   :*##%%###%%#%##%##%#*++=##**##*##++*++===*#***+++**+++===:.  " << std::endl;
	outfile << "               .=****##%###%##%%%#########################**+-=*=======**++=+==.== " << std::endl;
	outfile << "             -+++**#####*-+###%%#*###*####%######**#**#*+###+==+#**--+==#*#**+==+=  -.    : " << std::endl;
	outfile << "            :+++***######%%##**#%%#%%#*#***####++###**=+=+++**+==*+=++*++++#*+=*+==++=.:=-=- " << std::endl;
	outfile << "                .**#*#####%%#**#%#%*#**###*%#*#**++==-++*=+===+*##+-*==-====***+=+-=+++====. " << std::endl;
	outfile << "              ..-:%*####%%%##%%%%##*########*+++++##**+*=*++*==++===##+===+=-+*#===-=*===-=-:. " << std::endl;
	outfile << "             =-#%%#%######%%%%#############*#########*==+++*=**###*++*****===+*#*++-----+*+==- " << std::endl;
	outfile << "             .+##%##########%#%#%%#####*#############*######**##****+++*#*#*++*#*#*=+-++--==-- " << std::endl;
	outfile << "           .%%####*#####%%%##%#%%#######***%%#**##%#=*****+*#*+=++=+==++++**+*****++*++++=-: . " << std::endl;
	outfile << "          -*#%%####%%%%%#%%###%###*###%%##%%#-#%###+:***#**=+*+*++=+**+*****+==***+***====--: " << std::endl;
	outfile << "        -#%#%#%###%%%%%#*.=*=*%######*####*%##+####%######****#***=--++*++*##***=+==+: .: " << std::endl;
	outfile << "       =##**#%%##%%%%%%-=%%%%#%%%%##*##%##%%#%#################*+++***++---=--+*=-:---:. " << std::endl;
	outfile << "            =*#%%%=::   +-  :#######%####..+%########%%****####**+*++*++=++*=+-----:-=:-.. " << std::endl;
	outfile << "           +*#%##==- #%##%+#%%##%%##-+%%%%*#*###*#+     --*= =+##*===-====+==**+----::-:---- " << std::endl;
	outfile << "                  :+=**:   +###+==.   -+#*########-              =+*++=:--.-+----====-:: " << std::endl;
	outfile << "                      .:::.                 *#####-              . .--::-+---===..--==--=--- " << std::endl;
	outfile << "                                             ####%:                   . ..--::=-:: ..-: .-- " << std::endl;
	outfile << "                                             ##*** ..:=-=:. " << std::endl;
	outfile << "                                             +**+**#- =                      .-:.-. " << std::endl;
	outfile << "                               .-+*#*%#%####***##*%%##%####++.              " << std::endl;
	outfile << "                           +%###%##############*#################*#####+:   " << std::endl;
	outfile << "                           .#%%%%%%%%%###################################-  " << std::endl;

	

	outfile.close();
}