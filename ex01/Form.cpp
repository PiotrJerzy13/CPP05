/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:42:48 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/12 10:47:46 by piotr            ###   ########.fr       */
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

const std::string& Form::getName() const noexcept { return details.getName(); }
bool Form::getIsSigned() const noexcept { return isSigned; }
int Form::getToSign() const noexcept { return details.getSignGrade(); }
int Form::getToExec() const noexcept { return details.getExecGrade(); }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (isSigned)
	{
		std::cout << bureaucrat.getName() << " cannot sign " << details.getName()
				  << " because it's already signed.\n";
		return;
	}

	if (bureaucrat.getGrade() > details.getSignGrade())
		throw GradeTooLowException();
	
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form signing/execution failed: Grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form signing/execution failed: Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << " Form: isSigned = " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign = " << form.getToSign()
	   << ", grade to execute = " << form.getToExec();
	return os;
}
