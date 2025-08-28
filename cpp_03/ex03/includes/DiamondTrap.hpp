/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:56 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:52:56 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
  private:
    std::string _name;
  public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    using ScavTrap::attack;
    void whoAmI();
};
