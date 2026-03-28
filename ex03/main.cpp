/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:16:51 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/28 10:28:07 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

class Bureaucrat;
class ShrubberyCreationForm;

int	main(void)
{
	{
		std::cout << "1) Good" << std::endl;
		AForm					*f;
		std::string				target = "newFile";
		f = Intern::makeForm(SH_NAME, target);
		if (f != NULL)
		{
			try
			{
				Bureaucrat				b("John", 3);
				f->beSigned(b);
				std::cout << "Signed" << std::endl;
				f->execute(b);
				std::cout << b.getName() << " executed " << f->getName() << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			delete f;
		}
			std::cout << std::endl;
	}
	{
		std::cout << "2) Good" << std::endl;
		AForm					*f;
		std::string				target = "criminal";
		f = Intern::makeForm(PP_NAME, target);
		if (f != NULL)
		{
			try
			{
				Bureaucrat				b("John", 3);
				f->beSigned(b);
				std::cout << "Signed" << std::endl;
				f->execute(b);
				std::cout << b.getName() << " executed " << f->getName() << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			delete f;
		}
			std::cout << std::endl;
	}
	{
		std::cout << "3) Good" << std::endl;
		AForm					*f;
		std::string				target = "human";
		f = Intern::makeForm(RR_NAME, target);
		if (f != NULL)
		{
			try
			{
				Bureaucrat				b("John", 3);
				f->beSigned(b);
				std::cout << "Signed" << std::endl;
				f->execute(b);
				std::cout << b.getName() << " executed " << f->getName() << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			delete f;
		}
			std::cout << std::endl;
	}
	{
		std::cout << "4) Bad form name" << std::endl;
		AForm					*f;
		std::string				target = "criminal";
		f = Intern::makeForm("wrong form", target);
		if (f != NULL)
		{
			try
			{
				Bureaucrat				b("John", 3);
				f->beSigned(b);
				std::cout << "Signed" << std::endl;
				f->execute(b);
				std::cout << b.getName() << " executed " << f->getName() << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			delete f;
		}
		else
			std::cout << "ERROR creating form" << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
