/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:51 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 15:12:45 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"
#include <iostream>

// Construtor padrão
DiamondTrap::DiamondTrap() 
    : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default") {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = ScavTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created (default constructor)" << std::endl;
}

// Construtor com parâmetro
DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = ScavTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

// Construtor de cópia
DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << "DiamondTrap " << _name << " copied" << std::endl;
}

// Operador de atribuição
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap " << this->_name << " assigned" << std::endl;
    return *this;
}

// Destrutor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

// Método de ataque
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

// Método whoAmI
void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << _name << " | ClapTrap name: " << ClapTrap::_name << std::endl;
}