/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:42:48 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 19:34:08 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() noexcept
	: details("Default", 150, 150), isSigned(false) {}

Form::Form(std::string_view name, int toSign, int toExec)
	: details(std::string(name), toSign, toExec), isSigned(false) {}

Form::Form(const Form &other)
	: details(other.details), isSigned(other.isSigned) {}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		isSigned = other.isSigned;
	}
	return *this;
}

std::string_view Form::getName() const noexcept { return details.getName(); }
bool Form::getIsSigned() const noexcept { return isSigned; }
int Form::getToSign() const noexcept { return details.getSignGrade(); }
int Form::getToExec() const noexcept { return details.getExecGrade(); }

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > details.getSignGrade())
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " Form: isSigned = " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign = " << form.getToSign()
	   << ", grade to execute = " << form.getToExec() << '\n';
	return os;
}