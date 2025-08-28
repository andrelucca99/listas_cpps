/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:21 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:59:56 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main() {
  DiamondTrap dia("DI4M");

  dia.attack("target");
  dia.takeDamage(20);
  dia.beRepaired(10);
  dia.whoAmI();

  return 0;
}