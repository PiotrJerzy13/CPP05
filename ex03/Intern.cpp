/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:48:33 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 15:06:21 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <functional>

using FormFactory = std::function<std::unique_ptr<AForm>(const std::string&)>;

static const std::string formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

static const FormFactory formFunctions[3] = {
	[](const std::string& target) -> std::unique_ptr<AForm> { return std::make_unique<ShrubberyCreationForm>(target); },
	[](const std::string& target) -> std::unique_ptr<AForm> { return std::make_unique<RobotomyRequestForm>(target); },
	[](const std::string& target) -> std::unique_ptr<AForm> { return std::make_unique<PresidentialPardonForm>(target); }
};

Intern::Intern() = default;
Intern::Intern(const Intern& other) = default;
Intern& Intern::operator=(const Intern& other) = default;
Intern::~Intern() = default;

std::unique_ptr<AForm> Intern::makeForm(const std::string& form, const std::string& target) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return formFunctions[i](target);
		}
	}

	std::cerr << "No matching form found for '" << form << "'" << std::endl;
	return nullptr;
}
