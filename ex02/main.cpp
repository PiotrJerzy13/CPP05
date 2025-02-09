/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:16:14 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 14:34:09 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testBureaucrat()
{
    std::cout << "\n=== TEST: Bureaucrat Creation and Grade Management ===\n";

    try
    {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        std::cout << "Incrementing Bob's grade...\n";
        bob.incrementGrade();
        std::cout << bob << std::endl;

        std::cout << "Decrementing Bob's grade...\n";
        bob.decrementGrade();
        std::cout << bob << std::endl;

        std::cout << "Trying to create a Bureaucrat with an invalid grade...\n";
        Bureaucrat invalid("Invalid", 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to create a Bureaucrat with grade 151...\n";
        Bureaucrat invalid("Too Low", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void testForms()
{
    std::cout << "\n=== TEST: Forms Signing and Execution ===\n";

    Bureaucrat alice("Alice", 1);
    Bureaucrat charlie("Charlie", 75);
    Bureaucrat dave("Dave", 140);

    PresidentialPardonForm pardonForm("Arthur Dent");
    RobotomyRequestForm robotomyForm("Marvin the Paranoid Android");
    ShrubberyCreationForm shrubberyForm("Garden");

    std::cout << "\n--- Alice signs all forms ---\n";
    alice.signForm(pardonForm);
    alice.signForm(robotomyForm);
    alice.signForm(shrubberyForm);

    std::cout << "\n--- Alice executes all forms ---\n";
    bool pardonSuccess = pardonForm.execute(alice);
    std::cout << "Presidential Pardon execution: " << (pardonSuccess ? "SUCCESS" : "FAIL") << std::endl;

    bool robotomySuccess = robotomyForm.execute(alice);
    std::cout << "Robotomy execution: " << (robotomySuccess ? "SUCCESS" : "FAIL") << std::endl;

    bool shrubberySuccess = shrubberyForm.execute(alice);
    std::cout << "Shrubbery execution: " << (shrubberySuccess ? "SUCCESS" : "FAIL") << std::endl;

    std::cout << "\n--- Charlie tries to execute PresidentialPardonForm (should fail) ---\n";
    try
    {
        bool result = pardonForm.execute(charlie);
        std::cout << "Presidential Pardon execution: " << (result ? "SUCCESS" : "FAIL") << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Charlie executes RobotomyRequestForm ---\n";
    try
    {
        bool result = robotomyForm.execute(charlie);
        std::cout << "Robotomy execution: " << (result ? "SUCCESS" : "FAIL") << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Dave tries to execute ShrubberyCreationForm (should fail) ---\n";
    try
    {
        bool result = shrubberyForm.execute(dave);
        std::cout << "Shrubbery execution: " << (result ? "SUCCESS" : "FAIL") << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Shrubbery file should now be created ---\n";
}

int main()
{
    std::cout << "=== BEGIN TESTS ===\n";

    testBureaucrat();
    testForms();

    std::cout << "\n=== ALL TESTS COMPLETED ===\n";
    return 0;
}

