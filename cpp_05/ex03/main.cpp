/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:09:01 by alucas-e          #+#    #+#             */
/*   Updated: 2025/11/18 13:27:55 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Intern.hpp"
#include "./includes/Bureaucrat.hpp"

int main() {
    Intern intern;
    AForm* f1;
    AForm* f2;
    AForm* f3;

    f1 = intern.makeForm("shrubbery creation", "Garden");
    f2 = intern.makeForm("robotomy request", "Bender");
    f3 = intern.makeForm("presidential pardon", "Arthur Dent");

    Bureaucrat boss("Boss", 1);

    std::cout << std::endl;
    if (f1) { boss.signForm(*f1); boss.executeForm(*f1); }
    if (f2) { boss.signForm(*f2); boss.executeForm(*f2); }
    if (f3) { boss.signForm(*f3); boss.executeForm(*f3); }

    delete f1;
    delete f2;
    delete f3;

    return 0;
}
