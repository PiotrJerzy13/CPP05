/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:28:50 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/08 17:56:16 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() noexcept : name("Default"), grade(1) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string_view name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) noexcept : name(other.name), grade(other.grade) {}

// Destructor
Bureaucrat::~Bureaucrat() noexcept {}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) noexcept
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

// Getters
std::string Bureaucrat::getName() const noexcept { return name; }
int Bureaucrat::getGrade() const noexcept { return grade; }

// Grade modification methods
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

// Exception implementations
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Exception caught: Grade is not valid, is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Exception caught: Grade is not valid, is too low";
}

// Overloaded insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}