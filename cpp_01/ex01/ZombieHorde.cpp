/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:33:39 by andre             #+#    #+#             */
/*   Updated: 2025/07/25 12:42:42 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  if (N <= 0) return NULL;

  Zombie* horde = new Zombie[N];

  for (int i = 0; i < N; i++) {
    horde[i].setName(name + "_" + std::to_string(i + 1));
  }
  return horde;
}