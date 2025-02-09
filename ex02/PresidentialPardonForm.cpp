/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:03:14 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 14:31:06 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string_view target) 
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

std::string PresidentialPardonForm::getTarget() const { return target; }

bool PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
	{
		std::cerr << "PresidentialPardonForm: " << getName() << " is not signed, cannot execute.\n";
		return false;
	}
	if (executor.getGrade() > getToExec())
	{
		std::cerr << "Bureaucrat grade too low to execute " << getName() << ".\n";
		throw GradeTooLowException();
	}

	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
	return true;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	os << form.getName() << " PresidentialPardonForm, isSigned: " << std::boolalpha << form.getIsSigned()
	   << ", grade required to sign: " << form.getToSign()
	   << ", grade required to execute: " << form.getToExec()
	   << ", target: " << form.getTarget();
	return os;
}
