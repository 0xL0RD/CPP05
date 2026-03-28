/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:07:34 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/28 10:24:55 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*	Intern::newShrubberyCreationForm(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::newPresidentialPardonForm(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::newRobotomyRequestForm(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string &target)
{
	int	len;
	int	i;
	std::string names[] = {
		SH_NAME,
		PP_NAME,
		RR_NAME
	};
	AForm* (*formCreator[])(std::string &target) = {
		newShrubberyCreationForm,
		newPresidentialPardonForm,
		newRobotomyRequestForm
	};
	
	len = sizeof(names) / sizeof(names[0]);
	for (i = 0; i < len; i++)
	{
		if (formName == names[i])
			return (formCreator[i](target));
	}
	return (NULL);
}
