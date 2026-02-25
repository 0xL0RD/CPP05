/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:28:28 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 08:46:58 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b("Pepe", 1);

	try
	{
		Bureaucrat c("Maria", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat c("Maria", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat c("Maria", 1);
		c.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat c("Maria", 150);
		c.decrementGrade();
		std::cout << "---" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	{
		Bureaucrat c("Pepe", 76);
		std::cout << c << std::endl;
	}
	{
		Bureaucrat a("Ana", 88);
		Bureaucrat a2(a);
		std::cout << "Ana:" << std::endl;
		std::cout << a << std::endl;
		std::cout << "Ana copy:" << std::endl;
		std::cout << a2 << std::endl;
	}
	{
		Bureaucrat a("Ana", 88);
		Bureaucrat j("Jose", 122);
		std::cout << "Ana:" << std::endl;
		std::cout << a << std::endl;
		std::cout << "Jose:" << std::endl;
		std::cout << j  << std::endl;
		j = a;
		std::cout << "Jose (after =ing):" << std::endl;
		std::cout << j  << std::endl;
	}
}
