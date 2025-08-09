/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:35:42 by andre             #+#    #+#             */
/*   Updated: 2025/08/09 09:47:15 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

// int main(void) {
//   Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;

//   return 0;
// }

int main() {
    Fixed a(5.05f);
    Fixed b(0); // divisor zero

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // Aqui deve acontecer o "crash" (comportamento indefinido)
    Fixed c = a / b;

    std::cout << "Resultado: " << c << std::endl; // provavelmente não vai ser executado
    return 0;
}
