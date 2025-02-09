/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:03:37 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 19:28:37 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	explicit PresidentialPardonForm(std::string_view target);
	~PresidentialPardonForm() override = default;

	[[nodiscard]] std::string getTarget() const;
	[[nodiscard]] bool execute(const Bureaucrat& executor) const override;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif