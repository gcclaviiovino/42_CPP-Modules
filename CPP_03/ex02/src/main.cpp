#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	coolClap("cool");

	ScavTrap	coolScav("slay");

	FragTrap	coolFrag("yay");
	FragTrap	copyCoolFrag(coolFrag);
	FragTrap	assignedCoolFrag("assigned");
	
	assignedCoolFrag = coolFrag;

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
	coolScav.guardGate();
	coolFrag.attack("target");
	coolFrag.takeDamage(10);
	copyCoolFrag.beRepaired(5);
	copyCoolFrag.attack("obstacle");
	coolFrag.highFivesGuys();
}