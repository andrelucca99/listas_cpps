/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/02 13:47:58 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array {
  private:
    T* _data;
    unsigned int _size;
  public:
    Array() : _data(NULL), _size(0) {}
    Array(unsigned int n) : _size(n) {
      _data = new T[n];
    }
    Array(const Array& other) : _data(NULL), _size(0) {
      *this = other;
    }
    ~Array() {
      delete[] _data;
    }

    Array& operator=(const Array& other) {
      if (this != &other) {
        delete[] _data;
        _size = other._size;

        _data = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
          _data[i] = other._data[i];
      }
      return *this;
    }

    T& operator[](unsigned int index) {
      if (index >= _size)
        throw std::out_of_range("Index out of bounds");
      return _data[index];
    }

    const T& operator[](unsigned int index) const {
      if (index >= _size)
        throw std::out_of_range("Index out of bounds");
      return _data[index];
    }

    unsigned int size() const {
      return _size;
    }
};
