/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:38:42 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 14:38:44 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int toSign;
		const int toExec;

	public:
		AForm();
		explicit AForm(std::string_view name, int toSign, int toExec);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);

		void beSigned(const Bureaucrat& bureaucrat);
		[[nodiscard]] virtual bool execute(const Bureaucrat& executor) const = 0;

		[[nodiscard]] std::string getName() const;
		[[nodiscard]] bool getIsSigned() const;
		[[nodiscard]] int getToSign() const;
		[[nodiscard]] int getToExec() const;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif