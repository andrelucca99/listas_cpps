/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:09:52 by andre             #+#    #+#             */
/*   Updated: 2025/11/24 11:04:39 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{
	private:
		// Construtor privado → impede instanciar
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& literal);

	private:
		// Funções de detecção
		static bool isChar(const std::string& s);
		static bool isInt(const std::string& s);
		static bool isFloat(const std::string& s);
		static bool isDouble(const std::string& s);
		static bool isPseudoLiteral(const std::string& s);

		// Funções de conversão
		static void fromChar(char c);
		static void fromInt(int n);
		static void fromFloat(float f);
		static void fromDouble(double d);
};
