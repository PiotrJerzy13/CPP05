/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:06:38 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 12:39:26 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), toSign(50), toExec(20), isSigned(false) {}

AForm::AForm(std::string_view name, int toSign, int toExec)
	: name(name), toSign(toSign), toExec(toExec), isSigned(false) {}

AForm::AForm(const AForm& other)
	: name(other.name), toSign(other.toSign), toExec(other.toExec), isSigned(other.isSigned) {}

AForm::~AForm() = default;

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getToSign() const { return toSign; }
int AForm::getToExec() const { return toExec; }

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low.";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > toSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << " Form, isSigned: " << std::boolalpha << form.getIsSigned()
	   << ", grade required to sign: " << form.getToSign()
	   << ", grade required to execute: " << form.getToExec();
	return os;
}
