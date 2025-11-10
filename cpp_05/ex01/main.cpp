/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:09:01 by alucas-e          #+#    #+#             */
/*   Updated: 2025/11/10 15:11:14 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/Form.hpp"

int main() {
	try {
        Bureaucrat alice("Alice", 50);
        Form taxForm("Tax Declaration", 75, 100);

        std::cout << alice << std::endl;
        std::cout << taxForm << std::endl;

        alice.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat bob("Bob", 120);
        Form passport("Passport Request", 100, 110);
        bob.signForm(passport); // Deve falhar

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

	
	return 0;
}
