/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:04:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/02 13:27:41 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Iter.hpp"

class Awesome {
  public:
    Awesome(void) : _n(42) {}
    int get(void) const { return this->_n; }
  private:
    int _n;
};

std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}

int main(void) {
  int tab[] = {0, 1, 2, 3, 4};
  Awesome tab2[5];

  iter(tab, 5, printElement);
  iter(tab2, 5, printElement);

  return 0;
}
