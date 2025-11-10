/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:09:01 by alucas-e          #+#    #+#             */
/*   Updated: 2025/11/10 11:42:56 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << "After increment: " << a << std::endl;
		
		a.incrementGrade();
		std::cout << "This line will not run." << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat b("Bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
