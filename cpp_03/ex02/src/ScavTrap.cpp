/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:15:10 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:44:01 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav") {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;

  std::cout << "ScavTrap " << this->_name << " created (default constructor)" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << "ScavTrap " << this->_name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  *this = other;
  std::cout << "ScavTrap " << this->_name << " copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  ClapTrap::operator=(other);
  std::cout << "ScavTrap " << this->_name << " assigned" << std::endl;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (this->_hitPoints <= 0) {
    std::cout << "ScavTrap " << this->_name << " cannot attack, no hit points left!" << std::endl;
    return;
  }

  if (this->_energyPoints <= 0) {
    std::cout << "ScavTrap " << this->_name << " has no energy to attack!" << std::endl;
    return;
  }

  _energyPoints--;
  std::cout << "ScavTrap " << this->_name << " ferociously attacks " << target << ", dealing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;
}
