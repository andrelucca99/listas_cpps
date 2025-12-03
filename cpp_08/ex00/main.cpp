/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:04:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/03 08:08:35 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "./includes/Easyfind.hpp"

int main(void)
{
  std::vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  try {
      std::vector<int>::iterator it = easyfind(vec, 20);
      std::cout << "Value found: " << *it << std::endl;
  }
  catch (std::exception &e) {
      std::cout << e.what() << std::endl;
  }

  try {
      std::vector<int>::iterator it = easyfind(vec, 99);
      std::cout << "Value found: " << *it << std::endl;
  }
  catch (std::exception &e) {
      std::cout << e.what() << std::endl;
  }

  // Testando com list
  std::list<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);

  try {
      std::list<int>::iterator it = easyfind(lst, 3);
      std::cout << "List value: " << *it << std::endl;
  }
  catch (std::exception &e) {
      std::cout << e.what() << std::endl;
  }

  return 0;
}