/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:00 by andre             #+#    #+#             */
/*   Updated: 2025/12/02 13:47:50 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Test deep copy
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Values do not match!" << std::endl;
            return 1;
        }
    }

    // Test out-of-bounds
    try {
        numbers[-2];
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    try {
        numbers[MAX_VAL];
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;

    return 0;
}
