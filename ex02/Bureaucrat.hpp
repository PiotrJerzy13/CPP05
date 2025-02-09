/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:01:06 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 12:36:45 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <string_view>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string_view name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);

	[[nodiscard]] std::string_view getName() const noexcept;
	[[nodiscard]] int getGrade() const noexcept;

	void incrementGrade(int decrement);
	void decrementGrade(int increment);
	void signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
	public:
		[[nodiscard]] const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		[[nodiscard]] const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
