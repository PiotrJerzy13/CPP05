/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:33:57 by pwojnaro          #+#    #+#             */
/*   Updated: 2025/02/09 10:07:34 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testValidBureaucrats()
{
	std::cout << "===== Testing Valid Bureaucrats =====" << std::endl;
	try
	{
		Bureaucrat a("Alice", 1);
		Bureaucrat b("Bob", 75);
		Bureaucrat c("Charlie", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
}

void testInvalidBureaucrats()
{
	std::cout << "\n===== Testing Invalid Bureaucrats =====" << std::endl;
	try
	{
		Bureaucrat tooHigh("HighRank", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("LowRank", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testGradeModification()
{
	std::cout << "\n===== Testing Grade Increments & Decrements =====" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 75);
		std::cout << worker << std::endl;

		std::cout << "Incrementing grade by 5..." << std::endl;
		worker.incrementGrade(5);
		std::cout << worker << std::endl;

		std::cout << "Decrementing grade by 10..." << std::endl;
		worker.decrementGrade(10);
		std::cout << worker << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}
}

void testIncrementBeyondLimit()
{
	std::cout << "\n===== Testing Grade Increment Beyond Limit =====" << std::endl;
	try
	{
		Bureaucrat top("TopBureaucrat", 1);
		std::cout << top << std::endl;
		std::cout << "Trying to increment beyond grade 1..." << std::endl;
		top.incrementGrade(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void testDecrementBeyondLimit()
{
	std::cout << "\n===== Testing Grade Decrement Beyond Limit =====" << std::endl;
	try
	{
		Bureaucrat bottom("BottomBureaucrat", 150);
		std::cout << bottom << std::endl;
		std::cout << "Trying to decrement beyond grade 150..." << std::endl;
		bottom.decrementGrade(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

int main()
{
	testValidBureaucrats();
	testInvalidBureaucrats();
	testGradeModification();
	testIncrementBeyondLimit();
	testDecrementBeyondLimit();
	return 0;
}
