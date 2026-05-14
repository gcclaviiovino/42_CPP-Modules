#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	cool("cool");
	ClapTrap	copyCool(cool);
	ClapTrap	assignedCool("assigned");

	assignedCool = cool;

	cool.attack("bench");
	assignedCool.takeDamage(5);
	copyCool.takeDamage(6);
	cool.attack("tree");
	cool.beRepaired(3);
	cool.attack("bench");
	assignedCool.attack("car");
	for (int i = 0; i < 7; i++)
		cool.attack("bench");
	for (int i = 0; i < 3; i++)
		cool.beRepaired(2);
}