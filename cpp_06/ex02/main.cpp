/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:09:08 by andre             #+#    #+#             */
/*   Updated: 2025/11/26 13:31:23 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void)
{
	 std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Fazer vários testes:
    for (int i = 0; i < 5; ++i) {
        Base* p = generate();
        // opcional: imprimir que tipo foi gerado enviando para identify
        identify(p);        // por ponteiro
        identify(*p);       // por referência
        delete p;
        std::cout << "----\n";
    }

    // Testar comportamento com um objeto concreto (A) criado manualmente:
    A a;
    identify(&a);
    identify(a);

    return 0;
}
