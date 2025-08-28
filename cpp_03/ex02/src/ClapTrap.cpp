/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:55 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:10:28 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << this->_name << " created (default constructor)" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << this->_name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  *this = other;
  std::cout << "ClapTrap" << this->_name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  std::cout << "ClapTrap " << this->_name << " assigned" << std::endl;
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->_name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (this->_hitPoints <= 0) {
    std::cout << "ClapTrap " << this->_name << " cannot attack, no hit points left!" << std::endl;
    return;
  }

  if (this->_energyPoints <= 0) {
    std::cout << "ClapTrap " << this->_name << " has no energy to attack!" << std::endl;
    return;
  }

  this->_energyPoints--;

  std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is already destroyed!" << std::endl;
        return;
    }

    this->_hitPoints -= amount;

    if (this->_hitPoints < 0) this->_hitPoints = 0;

    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Remaining HP: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
      std::cout << "ClapTrap " << this->_name << " cannot repair, it's destroyed!" << std::endl;
      return;
    }

    if (this->_energyPoints <= 0) {
      std::cout << "ClapTrap " << this->_name << " has no energy to repair!" << std::endl;
      return;
    }

    this->_hitPoints += amount;
    this->_energyPoints--;

    std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " HP! Current HP: " << this->_hitPoints << std::endl;
}
