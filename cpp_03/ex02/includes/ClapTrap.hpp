/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:36:59 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:23:16 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
  protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    ~ClapTrap();

    void attack(const std::string& target);    
    void takeDamage(unsigned int amount);    
    void beRepaired(unsigned int amount);    
};
