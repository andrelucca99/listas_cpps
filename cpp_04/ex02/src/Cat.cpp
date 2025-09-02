/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:48:04 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 14:06:05 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : _brain(new Brain()) {
  type = "Cat";
  std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  this->_brain = new Brain(*other._brain);
  std::cout << "Cat copied" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    Animal::operator=(other);
    delete this->_brain;
    this->_brain = new Brain(*other._brain);  
  }
  std::cout << "Cat assigned" << std::endl;
  return *this;
}

Cat::~Cat() {
  delete this->_brain;
  std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
  std::cout << "Meow! 🐱" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
  this->_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
  return this->_brain->getIdea(index);
}
