/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:04:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/04 07:15:54 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }

    try {
        RPN calc;
        int result = calc.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}