/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:16:16 by andre             #+#    #+#             */
/*   Updated: 2025/11/18 13:30:33 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

static AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {

    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(std::string) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target); // chama a função correta
        }
    }

    std::cout << "Intern couldn’t find form \"" << formName << "\"" << std::endl;
    return NULL;
}
