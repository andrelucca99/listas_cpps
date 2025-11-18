/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:57:42 by andre             #+#    #+#             */
/*   Updated: 2025/11/18 13:00:12 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string _target;

  public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const & executor) const;
};
