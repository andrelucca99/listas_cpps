/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:04:49 by andre             #+#    #+#             */
/*   Updated: 2025/07/25 12:20:12 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie
{
  private:
    std::string name;

  public:
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);