#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	coolClap("cool");
	ClapTrap	copyCoolClap(coolClap);
	ClapTrap	assignedCoolClap = coolClap;
	ClapTrap	superCoolClap("Super Cool");

	ScavTrap	coolScav("slay");
	ScavTrap	copyCoolScav(coolScav);
	ScavTrap	assignedCoolScav = coolScav;
	ScavTrap	superCoolScav("Super Slay");

	coolClap.attack("bench");
	superCoolClap.takeDamage(5);
	superCoolClap.beRepaired(3);
	superCoolClap.attack("wall");
	coolScav.attack("stranger");
	coolScav.takeDamage(6);
	coolClap.attack("tree");
	coolScav.beRepaired(3);
	coolClap.attack("bench");
	superCoolClap.attack("car");
	for (int i = 0; i < 9; i++)
		coolClap.attack("bench");
	for (int i = 0; i < 9; i++)
		superCoolClap.beRepaired(2);
	assignedCoolScav.guardGate();
}