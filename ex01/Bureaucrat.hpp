/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:39:36 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/12 10:39:33 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"
#include "FormDetails.hpp"

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
	
	Bureaucrat& operator=(const Bureaucrat& other) = delete;

	[[nodiscard]] const std::string& getName() const noexcept;
	[[nodiscard]] int getGrade() const noexcept;

	void incrementGrade(int amount);
	void decrementGrade(int amount);
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
