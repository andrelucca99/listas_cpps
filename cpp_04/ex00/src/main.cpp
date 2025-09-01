/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:57:43 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 09:59:42 by andre            ###   ########.fr       */
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

  dog->makeSound(); // Woof
  cat->makeSound(); // Meow

  delete dog;
  delete cat;

  std::cout << "\n--- Wrong Animals ---" << std::endl;
  const WrongAnimal* wrongCat = new WrongCat();

  wrongCat->makeSound(); // ❌ imprime "Wrong generic sound"
  delete wrongCat;

  return 0;
}
