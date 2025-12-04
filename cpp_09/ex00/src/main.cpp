/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:04:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/03 15:03:40 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    // Carrega o database fixo que o subject manda
    btc.loadDatabase("data.csv");

    // Processa o arquivo fornecido pelo usuário
    btc.processInput(argv[1]);

    return 0;
}