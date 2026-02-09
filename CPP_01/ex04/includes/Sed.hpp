#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <stdbool.h>

void		err_param(std::string error);
std::string	make_substitution(std::ifstream& filestream, std::string& s1, std::string& s2);


#endif