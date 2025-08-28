/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:14:41 by andre             #+#    #+#             */
/*   Updated: 2025/08/27 14:55:34 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
  public:
    FragTrap();                          
    FragTrap(std::string name);          
    FragTrap(const FragTrap& other);     
    FragTrap& operator=(const FragTrap& other); 
    ~FragTrap();

    void highFivesGuys(void);
};
