#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	coolClap("cool");

	ScavTrap	coolScav("slay");
	ScavTrap	copyCoolScav(coolScav);
	ScavTrap	assignedCoolScav("assigned");
	
	assignedCoolScav = coolScav;

	coolClap.attack("bench");
	coolScav.attack("stranger");
	coolScav.takeDamage(6);
	coolClap.attack("tree");
	coolScav.beRepaired(3);
	coolClap.attack("bench");
	for (int i = 0; i < 2; i++)
		coolClap.attack("bench");
	for (int i = 0; i < 3; i++)
		coolScav.beRepaired(2);
	copyCoolScav.guardGate();
}