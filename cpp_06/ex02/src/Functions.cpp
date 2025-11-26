/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:10:50 by andre             #+#    #+#             */
/*   Updated: 2025/11/26 13:31:05 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base* generate(void) {
	int r = std::rand() % 3;
	switch (r) {
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

void identify(Base* p) {
	if (!p) {
		std::cout << "identify(pointer): null pointer\n";
		return;
	}
	if (dynamic_cast<A*>(p)) {
		std::cout << "identify(pointer): A\n";
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "identify(pointer): B\n";
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "identify(pointer): C\n";
	} else {
		std::cout << "identify(pointer): Unknown\n";
	}
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "identify(reference): A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "identify(reference): B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "identify(reference): C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "identify(reference): Unknown" << std::endl;
}
