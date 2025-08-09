/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:34:03 by andre             #+#    #+#             */
/*   Updated: 2025/08/09 09:48:29 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
  std::cout << "Int constructor called" << std::endl;
  this->value = n << this->fracBits;
}

Fixed::Fixed(const float f) {
  std::cout << "Float constructor called" << std::endl;
  this->value = roundf(f * (1 << this->fracBits));
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->value = other.getRawBits();
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->value;
}

void Fixed::setRawBits(int const raw) {
  this->value = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(this->value) / (1 << this->fracBits);
}

int Fixed::toInt(void) const {
  return this->value >> this->fracBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

// Operadores de comparação

bool Fixed::operator>(const Fixed& other) const {
  return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
  return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->value != other.value;
}

// Operadores aritméticos

Fixed Fixed::operator+(const Fixed& other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

// Fixed Fixed::operator/(const Fixed& other) const {
//   return Fixed(this->toFloat() / other.toFloat());
// }

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.value == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        exit(1); // ou abort();
    }
    return Fixed(this->toFloat() / other.toFloat());
}


// Pré e pós incremento/decremento

Fixed& Fixed::operator++() {
  this->value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  ++(*this);
  return tmp;
}

Fixed& Fixed::operator--() {
  this->value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  --(*this);
  return tmp;
}

// Funções estáticas min/max

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}