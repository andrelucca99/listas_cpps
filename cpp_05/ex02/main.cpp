/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:09:01 by alucas-e          #+#    #+#             */
/*   Updated: 2025/11/18 13:01:59 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);

    ShrubberyCreationForm tree("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << std::endl << "--- Signing forms ---" << std::endl;
    boss.signForm(tree);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << std::endl << "--- Executing forms ---" << std::endl;
    worker.executeForm(tree);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    return 0;
}
