/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:29:44 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/08 17:46:26 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <string_view>
#include <exception>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:

	Bureaucrat() noexcept;
	Bureaucrat(std::string_view name, int grade);
	Bureaucrat(const Bureaucrat& other) noexcept;
	~Bureaucrat() noexcept;
	Bureaucrat& operator=(const Bureaucrat& other) noexcept;
	std::string getName() const noexcept;
	int getGrade() const noexcept;
	void incrementGrade(int decrement);
	void decrementGrade(int increment);


	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif