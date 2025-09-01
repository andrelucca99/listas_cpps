/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:42:15 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 09:47:47 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() {
  type = "Dog";
  std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  *this = other;
  std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  Animal::operator=(other);
  std::cout << "Dog assigned" << std::endl;
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof! 🐶" << std::endl;
}
