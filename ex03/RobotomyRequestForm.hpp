/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:42:50 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 15:07:18 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <random>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		explicit RobotomyRequestForm(std::string_view target);
		~RobotomyRequestForm() override = default;

		[[nodiscard]] std::string getTarget() const;
		[[nodiscard]] bool execute(const Bureaucrat& executor) const override;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif
