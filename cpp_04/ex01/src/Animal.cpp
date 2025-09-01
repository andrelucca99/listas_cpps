/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:32:04 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 09:46:45 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
  std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    type = other.type;
  }

  std::cout << "Animal assigned" << std::endl;
  return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const {
  return type;
}

void Animal::makeSound() const {
  std::cout << "Generic animal sound" << std::endl;
}
