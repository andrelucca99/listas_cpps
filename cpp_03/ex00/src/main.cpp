/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:21 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:08:57 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main() {
  ClapTrap a("Alpha");
  ClapTrap b("Beta");

  a.attack("Beta");
  b.takeDamage(5);

  b.beRepaired(3);
  b.attack("Alpha");
  a.takeDamage(2);

  return 0;
}