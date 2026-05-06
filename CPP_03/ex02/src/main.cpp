#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	FragTrap	coolFlag("flag");
	FragTrap	copyCoolFlag(coolFlag);
	FragTrap	assignedCoolFlag = coolFlag;
	FragTrap	superCoolFlag("Super Flag");

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
	coolFlag.attack("target");
	coolFlag.takeDamage(10);
	superCoolFlag.beRepaired(5);
	superCoolFlag.attack("obstacle");
	coolFlag.highFivesGuys();
	superCoolFlag.highFivesGuys();
}