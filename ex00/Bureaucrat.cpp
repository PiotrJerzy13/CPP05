/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:28:50 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/12 10:13:14 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() noexcept : name("Default"), grade(1) {}

Bureaucrat::Bureaucrat(std::string_view name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
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

void Bureaucrat::incrementGrade(int amount)
{
	if (grade - amount < 1)
		throw GradeTooHighException();
	grade -= amount;
}

void Bureaucrat::decrementGrade(int amount)
{
	if (grade + amount > 150)
		throw GradeTooLowException();
	grade += amount;
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
