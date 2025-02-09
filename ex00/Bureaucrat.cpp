/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:28:50 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 11:02:45 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::Bureaucrat(std::string_view name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
		// throw std::runtime_error("Artificial exception to test try-catch");
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() noexcept {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) noexcept
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const noexcept
{
	return name;
}

int Bureaucrat::getGrade() const noexcept
{
	return grade;
}

void Bureaucrat::incrementGrade(int decrement)
{
	int newGrade = grade - decrement;
	if (newGrade < 1)
		throw GradeTooHighException();
	grade = newGrade;
}

void Bureaucrat::decrementGrade(int increment)
{
	int newGrade = grade + increment;
	if (newGrade > 150)
		throw GradeTooLowException();
	grade = newGrade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Exception caught: Grade is not valid, is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Exception caught: Grade is not valid, is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
