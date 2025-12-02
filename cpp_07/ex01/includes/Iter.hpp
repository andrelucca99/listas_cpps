/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/02 13:26:28 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template<typename T>
void iter(T *array, size_t length, void (*func)(T const &))
{
  for (size_t i = 0; i < length; i++)
    func(array[i]);
}

template<typename T>
void printElement(T const &value)
{
  std::cout << value << std::endl;
}
