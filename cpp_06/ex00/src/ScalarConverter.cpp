/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:10:50 by andre             #+#    #+#             */
/*   Updated: 2025/11/23 10:35:50 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

// Construtores privados
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}


// =============================
// Detectores de tipo
// =============================

bool ScalarConverter::isChar(const std::string& s)
{
    return s.length() == 1 && !std::isdigit(s[0]);
}

bool ScalarConverter::isInt(const std::string& s)
{
    size_t i = 0;

    if (s[0] == '+' || s[0] == '-')
        i++;

    if (i >= s.length())
        return false;

    for (; i < s.length(); i++)
        if (!std::isdigit(s[i]))
            return false;

    return true;
}

bool ScalarConverter::isFloat(const std::string& s)
{
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;

    bool dot = false;
    bool digit = false;

    size_t i = 0;
    if (s[0] == '+' || s[0] == '-')
        i++;

    for (; i < s.length(); i++)
    {
        if (s[i] == 'f' && i == s.length() - 1)
            return digit; // precisa ter número antes do 'f'

        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (std::isdigit(s[i]))
            digit = true;
        else
            return false;
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string& s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;

    bool dot = false;
    bool digit = false;

    size_t i = 0;
    if (s[0] == '+' || s[0] == '-')
        i++;

    for (; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (std::isdigit(s[i]))
            digit = true;
        else
            return false;
    }
    return dot && digit;
}

bool ScalarConverter::isPseudoLiteral(const std::string& s)
{
    return (
        s == "nan"  || s == "nanf" ||
        s == "+inf" || s == "-inf" ||
        s == "+inff"|| s == "-inff"
    );
}

static void printPseudo(const std::string& s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (s == "+inf" || s == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (s == "-inf" || s == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// =============================
// Conversions
// =============================

void ScalarConverter::fromChar(char c)
{
  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;

  float f = static_cast<float>(c);
  double d = static_cast<double>(c);

  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::fromInt(int n)
{
  // char
  if (n < 0 || n > 255)
      std::cout << "char: impossible" << std::endl;
  else if (n < 32 || n > 126)
      std::cout << "char: Non displayable" << std::endl;
  else
      std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

  // int
  std::cout << "int: " << n << std::endl;

  // float / double
  std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(float f)
{
  // CHAR
  if (f < 0 || f > 255 || f != static_cast<int>(f))
  {
      std::cout << "char: impossible" << std::endl;
  }
  else if (f < 32 || f > 126)
  {
      std::cout << "char: Non displayable" << std::endl;
  }
  else
  {
      std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
  }

  // int
  if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
      std::cout << "int: impossible" << std::endl;
  else
      std::cout << "int: " << static_cast<int>(f) << std::endl;

  // float
  std::cout << "float: " << f;
  if (f == static_cast<int>(f))
      std::cout << ".0";
  std::cout << "f" << std::endl;

  // double
  std::cout << "double: " << static_cast<double>(f);
  if (f == static_cast<int>(f))
      std::cout << ".0";
  std::cout << std::endl;
}

void ScalarConverter::fromDouble(double d)
{
  if (d < 0 || d > 255 || d != static_cast<int>(d))
  {
    std::cout << "char: impossible" << std::endl;
  }
  else if (d < 32 || d > 126)
  {
    std::cout << "char: Non displayable" << std::endl;
  }
  else
  {
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  }

  // int
  if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
      std::cout << "int: impossible" << std::endl;
  else
      std::cout << "int: " << static_cast<int>(d) << std::endl;

  // float
  float f = static_cast<float>(d);
  std::cout << "float: " << f;
  if (d == static_cast<int>(d))
      std::cout << ".0";
  std::cout << "f" << std::endl;

  // double
  std::cout << "double: " << d;
  if (d == static_cast<int>(d))
      std::cout << ".0";
  std::cout << std::endl;
}


// =============================
// Função principal: convert()
// =============================

void ScalarConverter::convert(const std::string& s)
{
  if (isPseudoLiteral(s))
  {
    printPseudo(s);
    return;
  }

  if (isChar(s))
      return fromChar(s[0]);

  if (isInt(s))
      return fromInt(std::atoi(s.c_str()));

  if (isFloat(s))
      return fromFloat(std::strtof(s.c_str(), NULL));

  if (isDouble(s))
      return fromDouble(std::strtod(s.c_str(), NULL));

  std::cout << "Invalid literal" << std::endl;
}
