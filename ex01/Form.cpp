/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:42:48 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 10:56:24 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() noexcept
    : name("Default"), isSigned(false) ,toSign(50), toExec(20) {}

Form::Form(std::string_view name, int toSign, int toExec)
    : name(name), isSigned(false), toSign(toSign), toExec(toExec)
{
    if (toSign < 1 || toExec < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), toSign(other.toSign), toExec(other.toExec) {}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}

std::string_view Form::getName() const noexcept { return name; }
bool Form::getIsSigned() const noexcept { return isSigned; }
int Form::getToSign() const noexcept { return toSign; }
int Form::getToExec() const noexcept { return toExec; }

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
    if (bureaucrat.getGrade() > toSign)
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
