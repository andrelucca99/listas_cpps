/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 12:24:58 by andre             #+#    #+#             */
/*   Updated: 2025/07/25 12:39:56 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
  int N = 5;
  Zombie* horde = zombieHorde(N, "Zombie");

  if (!horde) {
    std::cerr << "Failed to create horde!" << std::endl;
    return 1;
  }

  for (int i = 0; i < N; i++)
    horde[i].announce();
  
  delete[] horde;
  return 0;
}