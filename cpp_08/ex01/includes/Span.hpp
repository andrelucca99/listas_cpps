/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/03 08:44:19 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span {
  private:
    unsigned int _maxSize;
    std::vector<int> _data;
  public:
    Span(unsigned int n) : _maxSize(n) {}
    Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {}
    Span &operator=(const Span &other) {
      if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
      }
      return *this;
    }
    ~Span() {}

    void addNumber(int n) {
      if (_data.size() >= _maxSize)
        throw std::runtime_error("Span is full");
      _data.push_back(n);
    }

    int shortestSpan() const {
      if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
      
      std::vector<int> tmp = _data;
      std::sort(tmp.begin(), tmp.end());

      int shortest = tmp[1] - tmp[0];

      for (size_t i = 1; i < tmp.size() - 1; i++) {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
          shortest = diff;
      }

      return shortest;
    }

    int longestSpan() const {
      if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span");
      
      int minVal = *std::min_element(_data.begin(), _data.end());
      int maxVal = *std::max_element(_data.begin(), _data.end());
    
      return maxVal - minVal;
    }

    template <typename Iter>
    void addRange(Iter begin, Iter end) {
      for (Iter it = begin; it != end; ++it) {
        addNumber(*it);
      }
    }
};
