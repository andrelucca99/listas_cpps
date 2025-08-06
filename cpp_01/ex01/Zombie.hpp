/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:28:17 by andre             #+#    #+#             */
/*   Updated: 2025/07/25 12:30:23 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie {
  private:
    std::string name;
  
  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void setName(const std::string& name);
    void announce() const;
};