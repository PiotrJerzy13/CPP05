/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:06:38 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 14:29:35 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), toSign(50), toExec(20) {}

AForm::AForm(std::string_view name, int toSign, int toExec)
	: name(name), isSigned(false), toSign(toSign), toExec(toExec) {}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), toSign(other.toSign), toExec(other.toExec) {}

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
