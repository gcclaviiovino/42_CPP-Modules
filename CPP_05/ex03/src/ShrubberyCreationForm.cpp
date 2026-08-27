#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShruberryCreationForm", 147, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other), target(other.target)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::ofstream	newFile((target + "_shruberry").c_str());
	if (!newFile)
	{
		std::cout << "Error occurred while creating file " << target + "_shruberry" << ". Please try again.";
		std::cout << std::endl;
		return ;
	}

	newFile << "	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⢀⣀⡀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
	newFile << "⠀⢀⢀⠠⢄⠀⠀⠘⠀⠠⠼⡀⠠⠤⣀⣀⣾⣷⡾⣿⣷⣀⢳⣿⣿⣿⣦⣆⡠⢀⣀⡸⠄⢀⠘⠤⢄⠀⠤⢄⢀⠀⠀⠀⠡⠜⠀⠀⠀\n";
	newFile << "⠀⠀⠀⠀⠀⠀⠀⢠⠀⠀⢠⠀⠀⢠⣿⣏⠱⢾⡙⢏⠟⡥⢩⠛⣼⠷⢫⡹⡿⢟⢿⣛⡿⣿⣷⣦⣠⣤⡄⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀\n";
	newFile << "⠀⠀⠰⠀⢰⠒⠁⠈⠒⣶⣬⣶⣟⠻⡹⢾⣿⠻⠍⠆⠈⠄⡀⢩⢆⠙⡀⠇⣉⢾⡾⣵⣾⣿⣯⢿⣟⣿⣿⣶⠐⠁⠐⠒⠁⠈⠀⠀⠀\n";
	newFile << "⠀⠀⢀⠀⢀⠀⢂⣰⣟⠏⡿⣿⣟⣳⣕⣻⣦⢋⡔⠀⠁⠠⠐⠈⡌⠀⢠⠐⣊⠲⣱⢻⡾⣽⣻⢿⣾⢟⣿⣿⣿⣤⣄⡀⠆⠸⠀⠀⠀\n";
	newFile << "⠀⠀⠈⠀⢰⣤⣶⣿⣯⣞⣽⣿⣛⢶⡺⣧⢆⣡⡀⠄⡁⠐⠤⢁⠢⢡⠄⣒⠦⢳⡡⣏⡖⢧⢫⢏⡜⣯⣿⣻⣽⢻⣿⣧⣄⣀⠀⠀⠀\n";
	newFile << "⠀⠠⢰⣶⠾⡟⡧⣿⢿⡿⣿⣽⣛⣶⣽⣯⣛⠤⣐⠈⡄⢩⠐⢂⡱⣠⢛⡴⢩⠳⣝⣭⢻⣭⡷⣎⣽⣽⣻⣷⢾⣩⣖⣿⡿⠋⠀⠀⠀\n";
	newFile << "⠀⠀⢀⣻⢮⡱⢻⣿⢯⣿⡙⡷⢻⡙⣾⣳⡿⣏⡙⣎⡐⡡⡜⢆⢧⡱⢎⠾⣥⢻⡼⣾⠻⡅⡛⡗⣿⢾⣻⣿⣟⣶⣿⣻⣷⡶⠀⠀⠀\n";
	newFile << "⠀⠨⢙⣿⣯⣷⡿⢇⠲⡅⠹⢈⠡⢏⡔⢫⣟⣾⣝⣦⣳⡱⣭⣞⢦⣝⢮⣻⡜⣧⣟⡹⠅⢀⠡⢙⠴⡻⢭⢓⡎⠗⣮⠿⣿⣦⡀⠀⠀\n";
	newFile << "⠀⢠⢭⡹⠬⣙⢳⡉⠂⢀⠐⠠⠑⡄⢬⢲⣹⣿⣿⣿⣷⣿⣷⣿⣷⣿⣿⣷⣹⣶⢏⡒⠀⠂⢀⠁⢊⠘⣇⠎⠘⡠⠃⡞⡥⠾⣧⡄⠀\n";
	newFile << "⢀⡸⡑⠆⠡⠐⢨⠚⠄⣀⠂⡅⢣⠼⣭⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣩⠀⢂⠀⠎⢠⠑⡈⠀⢂⠠⠑⠠⠜⡓⣎⣳⡦\n";
	newFile << "⡨⢒⠠⠀⡐⠈⡀⡘⠰⣠⢓⣬⢳⣿⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣡⡐⠆⡨⠘⡀⠆⢀⠐⠀⡂⢌⡡⢆⣹⠴⣻⠀\n";
	newFile << "⠁⣇⠒⡁⠄⡠⢡⢈⣅⠲⣭⢾⣿⣿⣿⣿⣿⣿⣿⣿⡯⠿⢿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣽⣡⡗⣱⡜⡰⢂⠠⡑⡌⢀⡳⢍⣦⢻⣏⠁\n";
	newFile << "⠀⠗⣏⢄⢣⡔⣢⠝⣆⠷⣮⣷⣿⣿⣿⣿⣿⡿⠟⢿⣿⣶⣼⣿⡿⣧⣿⣿⠾⠛⢛⣿⣿⣿⣿⣿⣼⠱⣊⠶⡱⣍⢦⠹⣜⡸⢿⣅⠀\n";
	newFile << "⠀⢀⠙⠘⡯⣶⣿⣞⣿⣿⣾⣿⣿⣿⣿⣿⠛⣟⣆⠀⠙⣿⣿⣿⣿⣿⣿⠃⡆⠀⠀⣿⣿⣿⣿⣿⣷⣯⢧⣓⡳⡜⡶⣫⢼⣹⡧⠛⠁\n";
	newFile << "⠀⠀⠁⠀⠐⠿⠿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠿⣿⣿⣆⠀⢸⣿⣿⣿⣿⡿⠀⠀⣀⣼⣿⣿⣿⣿⣿⣿⣿⣧⣿⣵⣫⡵⠯⠾⠽⠃⠀⠀\n";
	newFile << "⠀⠈⠈⠀⠸⠤⡀⠻⠿⠛⢙⠟⠟⠁⠧⠔⠀⠠⠍⠛⢿⣿⣿⣿⣿⣿⣇⣴⣾⣿⠟⢋⠉⠻⢿⣿⣿⣿⣿⡿⠿⡀⠠⠤⡀⢀⠀⠀⠀\n";
	newFile << "⠀⢀⠠⠀⢠⠀⠀⠘⠀⠀⠘⠀⠀⠀⡄⢀⠀⠄⠠⠁⠂⠹⣿⣿⣿⣿⣿⣿⠛⠀⠀⠜⠀⠀⠈⠀⠈⢈⠀⢠⠀⠁⠠⠀⠀⠘⠀⠀⠀\n";
	newFile << "⠀⠈⠀⠒⠂⠈⠒⢲⠀⠐⠲⠁⠐⠒⠁⠀⠒⠀⠈⠒⠎⠈⣿⣿⣿⣿⡟⠁⠐⠒⠀⢱⠒⠀⠰⠒⠊⠀⠒⠊⠈⠒⠂⠀⠖⢲⠀⠀⠀\n";
	newFile << "⠀⠐⠀⢀⡰⠀⢀⣀⠀⢀⣀⠄⢀⣀⠆⠐⢀⠀⠐⣀⡀⠀⣿⣿⣿⣿⣻⠀⠆⣀⠀⢀⣀⠀⢀⣀⡀⠀⠀⡐⠀⢀⡀⠀⣀⣀⠀⠀⠀\n";
	newFile << "⠀⢀⢀⠤⢄⠀⠄⠘⠀⠀⠌⡀⠀⠠⡀⢀⠠⠀⢀⠤⠀⠀⣿⣿⣿⣿⣿⠀⡀⠀⠀⡸⠀⠀⠈⠤⠀⢀⠀⢄⢀⠂⠄⠀⠁⠜⠀⠀⠀\n";
	newFile << "⠀⠀⠀⠀⠀⠀⠄⢠⠀⠀⢠⠂⠀⠀⠃⠀⠀⠀⠀⠀⡄⠀ ⣿⣿⣿⣿⣿⡀⠃⠀⠀⢠⠀⠀⢠⠀⠄⠀⠀⠀⠀⡄⠀⠀⡄⢠⠀⠀⠀\n";
	newFile << "⠀⢐⠰⠁⢐⠒⠀⠀⠂⠀⠈⠂⠈⡆⠰⠀⠒⠐⠁⢐⢒⣿⣿⣿⣿⣿⡇⡎⠀⠂⡊⠀⠀⠂⠀⠑⠐⠁⢰⠐⠁⠐⠂⠀⠈⠀⠀⠀\n";
	newFile << "⠀⠀⢀⠀⢀⢀⠀⠸⠀⠀⠸⠀⠀⠀⡀⠀⠀⡀⢀⠂⠆⣸⣿⣿⣿⣿⣿⡇⡀⠀⡀⠸⠀⠀⢈⠀⠁⢀⠀⢀⢀⠃⢀⠀⠅⠸⠀⠀⠀\n";
	newFile << "⠀⠈⠀⠀⠘⠀⠀⢀⠀⠀⢠⠂⠀⠀⠃⠈⠀⠀⠐⠀⠀⣾⣿⣿⣿⣿⣿⣿⣀⠀⠀⢡⠀⠀⢀⠀⡀⠈⠀⠈⠀⡀⠀⠀⡀⢠⠀⠀⠀\n";
	newFile << "⠀⠠⢀⠒⢢⠀⠐⠊⠀⠐⠊⠄⠐⠒⡄⣀⣂⣤⣤⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣬⣒⡀⠈⠒⠀⠀⠐⢢⠀⠑⠂⠀⠑⠈⠀⠀⠀\n";
	newFile << "⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠐⠀⠀⠀⠁⠈⢀⠈⠉⡉⠍⠉⡏⠉⠉⠉⠉⠉⢉⠉⠀⢰⠁⠀⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠐⠀⠀⠀\n";

	newFile.close();
	std::cout << "File " << target + "_shruberry" << " created successfully." << std::endl;
}