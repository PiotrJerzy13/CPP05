
#ifndef FORMDETAILS_HPP
#define FORMDETAILS_HPP

#include <string>
#include <stdexcept>

class FormDetails
{
public:
	FormDetails(std::string name, int signGrade, int execGrade);
	~FormDetails() = default;

	const std::string& getName() const noexcept;
	int getSignGrade() const noexcept;
	int getExecGrade() const noexcept;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

private:
	const std::string name;
	const int signGrade;
	const int execGrade;
};
#endif