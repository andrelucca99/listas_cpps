/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:09:08 by andre             #+#    #+#             */
/*   Updated: 2025/11/24 14:51:58 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Base.hpp"

Base* generate(void);
void identifyP(Base* p);
void identifyR(Base& p);

int main(void)
{
	 std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Fazer vários testes:
    for (int i = 0; i < 5; ++i) {
        Base* p = generate();
        // opcional: imprimir que tipo foi gerado enviando para identify
        identifyP(p);        // por ponteiro
        identifyR(*p);       // por referência
        delete p;
        std::cout << "----\n";
    }

    // Testar comportamento com um objeto concreto (A) criado manualmente:
    A a;
    identifyP(&a);
    identifyR(a);

    return 0;
}
