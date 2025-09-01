/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:46:12 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 13:52:18 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
  std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain& other) {
  *this = other;
  std::cout << "Brain copied" << std::endl; 
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < 100; i++) {
      ideas[i] = other.ideas[i];
    }
  }
  std::cout << "Brain assigned" << std::endl;
  return *this;
}

Brain::~Brain() {
  std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
  if (index >= 0 && index < 100)
    ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < 100)
    return ideas[index];
  return "";
}
