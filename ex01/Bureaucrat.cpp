/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:41:17 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/12 10:26:38 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string_view name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() = default;

const std::string& Bureaucrat::getName() const noexcept { return name; }
int Bureaucrat::getGrade() const noexcept { return grade; }

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
