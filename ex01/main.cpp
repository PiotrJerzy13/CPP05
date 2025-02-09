/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:45:39 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 11:20:44 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void testValidForms()
{
	std::cout << "===== Testing Valid Forms =====" << std::endl;
	try
	{
		Form form1("Contract", 50, 30);
		Form form2("TaxForm", 100, 75);
		Form form3("Application", 150, 150);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
}

void testInvalidForms()
{
	std::cout << "\n===== Testing Invalid Forms =====" << std::endl;
	try
	{
		Form tooHigh("ImpossibleForm", 0, 30);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Form tooLow("UnreachableForm", 151, 75);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testFormSigningSuccess()
{
	std::cout << "\n===== Testing Form Signing Success =====" << std::endl;
	try
	{
		Bureaucrat signer("Alice", 40);
		Form importantForm("Important", 50, 30);

		std::cout << "Before signing: " << importantForm;
		signer.signForm(importantForm);
		std::cout << "After signing: " << importantForm;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
}

void testFormSigningFailure()
{
	std::cout << "\n===== Testing Form Signing Failure =====" << std::endl;
	try
	{
		Bureaucrat lowRank("Bob", 100);
		Form strictForm("StrictForm", 50, 30);

		std::cout << "Before signing: " << strictForm;
		lowRank.signForm(strictForm);
		std::cerr << "ERROR: Bob should NOT have been able to sign the form!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Correctly caught exception: " << e.what() << std::endl;
	}
}

void testFormOutput()
{
	std::cout << "\n===== Testing Form Output =====" << std::endl;
	Form exampleForm("ExampleForm", 75, 50);
	std::cout << "Expected output: 'ExampleForm Form: isSigned = false, grade to sign = 75, grade to execute = 50'" << std::endl;
	std::cout << "Actual output: " << exampleForm;
}

int main()
{
	testValidForms();
	testInvalidForms();
	testFormSigningSuccess();
	testFormSigningFailure();
	testFormOutput();
	return 0;
}
