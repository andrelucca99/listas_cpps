/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/03 08:07:35 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
  typename T::iterator it;

  it = std::find(container.begin(), container.end(), value);

  if (it == container.end())
    throw std::runtime_error("Value not found in container");
  return it;
}
