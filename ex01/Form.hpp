/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 09:42:08 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 19:34:14 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "FormDetails.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <string_view>

class Bureaucrat;

class Form
{
private:
	FormDetails details;
	bool isSigned;

public:
	Form() noexcept;
	explicit Form(std::string_view name, int toSign, int toExec);
	Form(const Form &other);
	Form& operator=(const Form& other);
	~Form() = default;

	void beSigned(const Bureaucrat &bureaucrat);

	[[nodiscard]] std::string_view getName() const noexcept;
	[[nodiscard]] bool getIsSigned() const noexcept;
	[[nodiscard]] int getToSign() const noexcept;
	[[nodiscard]] int getToExec() const noexcept;

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

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif