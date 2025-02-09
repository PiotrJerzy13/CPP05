/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:45:51 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 19:31:47 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <random>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string_view target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

std::string RobotomyRequestForm::getTarget() const { return target; }

bool RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
	{
		std::cerr << "RobotomyRequestForm: " << getName() << " is not signed, cannot execute.\n";
		return false;
	}
	if (executor.getGrade() > getToExec())
	{
		std::cerr << "Bureaucrat grade too low to execute " << getName() << ".\n";
		throw GradeTooLowException();
	}
	
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 1);

	std::cout << "Drilling noises... *Bzzzzzt* *Whirrrr*\n";
	if (dis(gen) == 0)
	{
		std::cout << target << " has been robotomized successfully.\n";
	}
	else
	{
		std::cout << "Robotomy failed.\n";
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	os << form.getName() << " RobotomyRequestForm, isSigned: " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign: " << form.getToSign() << ", grade to execute: " << form.getToExec();
	return os;
}
