#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	cool("cool");
	ClapTrap	copyCool(cool);
	ClapTrap	assignedCool = cool;
	ClapTrap	superCool("Super Cool");

	cool.attack("bench");
	superCool.takeDamage(5);
	superCool.beRepaired(3);
	superCool.attack("wall");
	cool.takeDamage(6);
	cool.attack("tree");
	cool.beRepaired(3);
	cool.attack("bench");
	superCool.attack("car");
	for (int i = 0; i < 9; i++)
		cool.attack("bench");
	for (int i = 0; i < 9; i++)
		superCool.beRepaired(2);
}