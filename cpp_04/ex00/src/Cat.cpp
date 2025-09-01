/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:48:04 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 09:51:47 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() {
  type = "Cat";
  std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  *this = other;
  std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  Animal::operator=(other);
  std::cout << "Cat assigned" << std::endl;
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow! 🐱" << std::endl;
}
