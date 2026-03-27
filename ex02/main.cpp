/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:16:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/27 10:46:40 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;
class ShrubberyCreationForm;

int	main(void)
{
	{
		std::cout << "1) Good" << std::endl;
		std::string				formName = "ssForm";
		ShrubberyCreationForm	f(formName);
		Bureaucrat				b("John", 3);
		try
		{
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
		Bureaucrat				b("UnderLevel", 146);
		try
		{
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
		Bureaucrat				b("UnderLevel", 138);
		try
		{
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
