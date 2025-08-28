/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:21 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:28:38 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main() {
  ClapTrap clap("CL4P");
  ScavTrap scav("SC4V");

  std::cout << "\n--- ClapTrap actions ---\n";
  clap.attack("target1");
  clap.takeDamage(5);
  clap.beRepaired(3);

  std::cout << "\n--- ScavTrap actions ---\n";
  scav.attack("target2");
  scav.takeDamage(20);
  scav.beRepaired(10);
  scav.guardGate();

  return 0;
}