/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:06:38 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 19:26:41 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
	: details("Default", 50, 20), isSigned(false) {}

AForm::AForm(std::string_view name, int toSign, int toExec)
	: details(std::string(name), toSign, toExec), isSigned(false) {}

AForm::AForm(const AForm& other)
	: details(other.details), isSigned(other.isSigned) {}

AForm::~AForm() = default;

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

std::string AForm::getName() const { return details.getName(); }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getToSign() const { return details.getSignGrade(); }
int AForm::getToExec() const { return details.getExecGrade(); }

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
	if (bureaucrat.getGrade() > details.getSignGrade())
		throw GradeTooLowException();
	isSigned = true;
}

bool AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned)
	{
		std::cerr << getName() << " is not signed, cannot execute.\n";
		return false;
	}
	if (executor.getGrade() > getToExec())
	{
		std::cerr << "Bureaucrat grade too low to execute " << getName() << ".\n";
		throw GradeTooLowException();
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << " Form, isSigned: " << std::boolalpha << form.getIsSigned()
	   << ", grade required to sign: " << form.getToSign()
	   << ", grade required to execute: " << form.getToExec();
	return os;
}
