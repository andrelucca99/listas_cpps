/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:14:41 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:55:49 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
  public:
    ScavTrap();                          
    ScavTrap(std::string name);          
    ScavTrap(const ScavTrap& other);     
    ScavTrap& operator=(const ScavTrap& other); 
    ~ScavTrap();

    void attack(const std::string& target);

    void guardGate();
};
