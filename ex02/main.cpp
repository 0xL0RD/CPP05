/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:16:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/27 15:18:45 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Bureaucrat;
class ShrubberyCreationForm;

int	main(void)
{
	{
		std::cout << "1) Good" << std::endl;
		std::string				formName = "ssForm";
		ShrubberyCreationForm	f(formName);
		try
		{
			Bureaucrat				b("John", 3);
			f.beSigned(b);
			std::cout << "Signed" << std::endl;
			f.execute(b);
			std::cout << b.getName() << " executed " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "2) BAD: bad grade for signing" << std::endl;
		std::string				formName = "ssForm2";
		ShrubberyCreationForm	f(formName);
		try
		{
			Bureaucrat				b("UnderLevel", 146);
			f.beSigned(b);
			std::cout << "Signed" << std::endl;
			f.execute(b);
			std::cout << b.getName() << " executed " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "3) BAD: bad grade for executing" << std::endl;
		std::string				formName = "ssForm2";
		ShrubberyCreationForm	f(formName);
		try
		{
			Bureaucrat				b("UnderLevel", 138);
			f.beSigned(b);
			std::cout << "Signed" << std::endl;
			f.execute(b);
			std::cout << b.getName() << " executed " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "4) Good PresidentialPardonForm" << std::endl;
		std::string				formName = "CriminalppForm";
		PresidentialPardonForm	f(formName);
		try
		{
			Bureaucrat				b("VicePresident", 2);
			f.beSigned(b);
			std::cout << "Signed" << std::endl;
			f.execute(b);
			std::cout << b.getName() << " executed " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "5) Robotomizing" << std::endl;
		std::string				formName = "Person";
		RobotomyRequestForm		f(formName);
		try
		{
			Bureaucrat				b("Ministry of Robots", 2);
			f.beSigned(b);
			std::cout << "Signed" << std::endl;
			f.execute(b);
			std::cout << b.getName() << " executed " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << std::endl;
		std::cout << "6) Robotomizing: too high" << std::endl;
		std::string				formName = "Person";
		RobotomyRequestForm		f(formName);
		try
		{
			Bureaucrat				b("Ministry of Robots", 0);
			f.beSigned(b);
			std::cout << "Signed" << std::endl;
			f.execute(b);
			std::cout << b.getName() << " executed " << f.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}
