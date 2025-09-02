/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:42:15 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 13:59:31 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
  type = "Dog";
  std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
  this->_brain = new Brain(*other._brain);
  std::cout << "Dog copied" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
  }
  std::cout << "Dog assigned" << std::endl;
  return *this;
}

Dog::~Dog() {
  delete this->_brain;
  std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof! 🐶" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
  this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
  return this->_brain->getIdea(index);
}
