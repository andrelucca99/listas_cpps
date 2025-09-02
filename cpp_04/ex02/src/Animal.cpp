/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:32:04 by andre             #+#    #+#             */
/*   Updated: 2025/09/01 11:43:21 by alucas-e         ###   ########.fr       */
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
