/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:49:21 by alucas-e          #+#    #+#             */
/*   Updated: 2025/11/17 13:30:47 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighException();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
		
		std::cout << "AForm " << _name << " created (sign grade: " << _gradeToSign << ", exec grade: " << _gradeToExecute << ")" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form: " << f.getName()
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Grade to sign: " << f.getGradeToSign()
       << " | Grade to execute: " << f.getGradeToExecute();
    return os;
}
