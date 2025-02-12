/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormDetails.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:23:05 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/12 10:51:32 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMDETAILS_HPP
#define FORMDETAILS_HPP

#include <string>
#include <stdexcept>

class FormDetails
{
public:
	FormDetails() noexcept;
	explicit FormDetails(std::string name, int signGrade, int execGrade);
	~FormDetails() = default;

	[[nodiscard]] const std::string& getName() const noexcept;
	[[nodiscard]] int getSignGrade() const noexcept;
	[[nodiscard]] int getExecGrade() const noexcept;

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

private:
	const std::string name;
	const int signGrade;
	const int execGrade;
};

#endif

