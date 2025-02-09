/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:57:45 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 15:06:43 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <memory>

int main()
{
	{
		Bureaucrat john("John", 1);
		Intern intern;

		std::unique_ptr<AForm> form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			john.signForm(*form);
			bool success = form->execute(john);
			std::cout << "Execution result: " << (success ? "SUCCESS" : "FAIL") << "\n";
		}
		std::cout << std::endl;
	}

	{
		Bureaucrat john("John", 1);
		Intern intern;

		std::unique_ptr<AForm> form = intern.makeForm("robotomy request", "home");
		if (form)
		{
			john.signForm(*form);
			bool success = form->execute(john);
			std::cout << "Execution result: " << (success ? "SUCCESS" : "FAIL") << "\n";
		}
		std::cout << std::endl;
	}

	{
		Bureaucrat john("John", 1);
		Intern intern;

		std::unique_ptr<AForm> form = intern.makeForm("presidential pardon", "home");
		if (form)
		{
			john.signForm(*form);
			bool success = form->execute(john);
			std::cout << "Execution result: " << (success ? "SUCCESS" : "FAIL") << "\n";
		}
		std::cout << std::endl;
	}

	{
		Bureaucrat john("John", 1);
		Intern intern;

		std::unique_ptr<AForm> form = intern.makeForm("invalid form", "home");
		if (!form)
		{
			std::cout << "Intern failed to create the form.\n";
		}
		std::cout << std::endl;
	}

	return 0;
}

