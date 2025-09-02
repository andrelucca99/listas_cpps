/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:57:43 by andre             #+#    #+#             */
/*   Updated: 2025/09/01 13:17:55 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main() {
  std::cout << "--- Correct Animals ---" << std::endl;
  const Animal* dog = new Dog();
  const Animal* cat = new Cat();

  dog->makeSound();
  cat->makeSound();

  delete dog;
  delete cat;

  std::cout << "\n--- Wrong Animals ---" << std::endl;
  const WrongAnimal* wrongCat = new WrongCat();

  wrongCat->makeSound();
  delete wrongCat;

  return 0;
}
