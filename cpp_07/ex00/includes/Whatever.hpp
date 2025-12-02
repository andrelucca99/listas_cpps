/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/02 13:10:00 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template<typename T>
T const &min(T const &a, T const &b)
{
  return (b < a ? b : a);
}

template<typename T>
T const &max(T const &a, T const &b)
{
  return (a < b ? b : a);
}
