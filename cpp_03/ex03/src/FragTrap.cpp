/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:15:10 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:40:08 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag") {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " created (default constructor)" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap " << this->_name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << this->_name << " assigned" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->_name << " requests a positive high five! ✋" << std::endl;
}
