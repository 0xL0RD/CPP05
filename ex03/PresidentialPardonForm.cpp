/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:08:29 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/27 13:22:26 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &target)
	:	AForm(PP_NAME, PP_SIGN_MIN, PP_EXEC_MIN),
		_target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(
			const PresidentialPardonForm &other
		)
	:	AForm(other),
		_target(other._target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
			const PresidentialPardonForm &lhs
		)
{
	this->AForm::operator=(lhs);
	return (*this);
}

void	PresidentialPardonForm::execute_child(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

