/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:44:39 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 14:44:57 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string_view target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

std::string ShrubberyCreationForm::getTarget() const { return _target; }

bool ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned())
	{
		std::cerr << "ShrubberyCreationForm: " << getName() << " is not signed, cannot execute.\n";
		return false;
	}
	if (executor.getGrade() > getToExec())
	{
		std::cerr << "Bureaucrat grade too low to execute " << getName() << ".\n";
		throw GradeTooLowException();
	}

	std::string filename = _target + "_shrubbery";
	std::ofstream outFile(filename);

	if (!outFile)
	{
		std::cerr << "Failed to open file: " << filename << "\n";
		return false;
	}

	const std::string tree = R"(
       *      
      ***     
     *****    
    *******   
   *********  
  *********** 
 ************* 
       |||    
       |||    

       *      
      ***     
     *****    
    *******   
   *********  
  *********** 
 ************* 
       |||    
       |||    
)";

	outFile << tree;
	outFile.close();

	std::cout << "ASCII trees written to " << filename << " successfully.\n";
	return true;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
	os << form.getName() << " ShrubberyCreationForm, isSigned: " << std::boolalpha << form.getIsSigned()
	   << ", grade to sign: " << form.getToSign() << ", grade to execute: " << form.getToExec();
	return os;
}
