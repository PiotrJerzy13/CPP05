/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormDetails.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:22:54 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/12 10:51:55 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FormDetails.hpp"

FormDetails::FormDetails() noexcept
	: name("Default"), signGrade(150), execGrade(150) {}

FormDetails::FormDetails(std::string name, int signGrade, int execGrade)
	: name(std::move(name)), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

const std::string& FormDetails::getName() const noexcept { return name; }
int FormDetails::getSignGrade() const noexcept { return signGrade; }
int FormDetails::getExecGrade() const noexcept { return execGrade; }

const char* FormDetails::GradeTooHighException::what() const noexcept
{
	return "Grade is too high (must be ≥ 1).";
}

const char* FormDetails::GradeTooLowException::what() const noexcept
{
	return "Grade is too low (must be ≤ 150).";
}
