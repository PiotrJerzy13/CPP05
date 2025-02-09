/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:41:17 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 11:20:32 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() = default;

Bureaucrat::Bureaucrat(std::string_view name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() = default;

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

std::string_view Bureaucrat::getName() const noexcept { return name; }
int Bureaucrat::getGrade() const noexcept { return grade; }

void Bureaucrat::incrementGrade(int decrement)
{
	if (grade - decrement < 1)
		throw GradeTooHighException();
	grade -= decrement;
}

void Bureaucrat::decrementGrade(int increment)
{
	if (grade + increment > 150)
		throw GradeTooLowException();
	grade += increment;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Exception caught: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Exception caught: Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
