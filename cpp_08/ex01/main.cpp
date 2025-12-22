/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:04:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/22 08:51:57 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Span.hpp"

int main(void)
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int> v;
    for (int i = 0; i < 10000; i++)
        v.push_back(i);
    
    Span spRange(10000);
    spRange.addRange(v.begin(), v.end());

    std::cout << spRange.shortestSpan() << std::endl;
    std::cout << spRange.longestSpan() << std::endl;

    return 0;
}
