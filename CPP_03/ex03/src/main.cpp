#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	coolClap("cool");
	ScavTrap	coolScav("slay");
	FragTrap	coolFrag("yay");
	DiamondTrap	coolDiamond("rihanna");

	coolClap.attack("bench");
	coolScav.attack("stranger");
	coolScav.takeDamage(6);
	coolFrag.beRepaired(5);
	coolDiamond.attack("obstacle");
	coolFrag.highFivesGuys();
	coolDiamond.whoAmI();
}