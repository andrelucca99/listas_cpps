/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:40:37 by andre             #+#    #+#             */
/*   Updated: 2025/11/18 12:42:53 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;
  public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;  
};
