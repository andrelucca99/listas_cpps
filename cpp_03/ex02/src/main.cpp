/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:21 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:44:28 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main() {
  ClapTrap clap("CL4P");
  ScavTrap scav("SC4V");
  FragTrap frag("FR4G");

  std::cout << "\n--- ClapTrap actions ---\n";
  clap.attack("target1");
  clap.takeDamage(5);
  clap.beRepaired(3);

  std::cout << "\n--- ScavTrap actions ---\n";
  scav.attack("target2");
  scav.takeDamage(20);
  scav.beRepaired(10);
  scav.guardGate();

  std::cout << "\n--- FragTrap actions ---\n";
  frag.attack("target3");
  frag.takeDamage(30);
  frag.beRepaired(15);
  frag.highFivesGuys();

  return 0;
}