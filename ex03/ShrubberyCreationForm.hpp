/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:44:20 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 19:43:08 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		explicit ShrubberyCreationForm(std::string_view target);
		~ShrubberyCreationForm() override = default;

		[[nodiscard]] std::string getTarget() const;
		[[nodiscard]] bool execute(const Bureaucrat& executor) const override;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif
