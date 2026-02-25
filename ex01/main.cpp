/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:28:28 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 11:56:51 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Basic usage:" << std::endl;
		Form f("M600", 4, 8);
		std::cout << f << std::endl;
		Bureaucrat b("Funcionario", 5);
		std::cout << "Not possible to sign:" << std::endl;
		try
		{
			f.beSigned(b);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << f << std::endl;
		std::cout << "DO sign:" << std::endl;
		b.incrementGrade();
		f.beSigned(b);
		std::cout << f << std::endl;
	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Copy constructor / Copy assignement:" << std::endl;
		Form f("M601", 4, 8);
		Form f2(f);
		Bureaucrat b("Funcionario", 4);
		f.beSigned(b);
		std::cout << "Original -signed- form:" << std::endl;
		std::cout << f << std::endl;
		std::cout << "New copied form -not signed-:" << std::endl;
		std::cout << f2 << std::endl;
		f2 = f;
		std::cout << "Copied form2 -signed-:" << std::endl;
		std::cout << f2 << std::endl;

	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Bureaucrat signs:" << std::endl;
		Bureaucrat b("Funcionario", 150);
		Form f("M601", 150, 8);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Bureaucrat do NOT sign -ends gracefully-:" << std::endl;
		Bureaucrat b("Funcionario", 150);
		Form f("M601", 15, 8);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	{
		//Form f;
	}
	std::cout << "----------------" << std::endl;
	return (0);
}
