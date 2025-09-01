/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 09:57:43 by andre             #+#    #+#             */
/*   Updated: 2025/08/31 14:07:06 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main() {
    const int N = 4;
    Animal* animals[N];

    // Criando metade dogs e metade cats
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testando deep copy ---" << std::endl;
    Dog dog1;
    dog1.setIdea(0, "Chase the cat");
    Dog dog2 = dog1; // construtor de cópia

    std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

    dog2.setIdea(0, "Eat the bone");
    std::cout << "Dog1 idea after Dog2 change: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2 idea after change: " << dog2.getIdea(0) << std::endl;

    // Limpando memória
    for (int i = 0; i < N; i++) {
        delete animals[i];
    }

    return 0;
}
