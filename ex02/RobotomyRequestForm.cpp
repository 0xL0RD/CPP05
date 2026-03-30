/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:08:29 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/27 15:16:12 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
	:	AForm(RR_NAME, RR_SIGN_MIN, RR_EXEC_MIN),
		_target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	:	AForm(other),
		_target(other._target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &lhs)
{
	if (&lhs != this)
		this->AForm::operator=(lhs);
	return (*this);
}

void	RobotomyRequestForm::execute_child(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << "[DRILLING NOISES]" << std::endl;
	std::cout << "[DRILLING NOISES]" << std::endl;
	std::cout << "[DRILLING NOISES]" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 + 1 == 1)
			std::cout << this->_target
			<< " has been robotomized" << std::endl;
	else
			std::cout << this->_target
			<< " robotomy FAILED" << std::endl;
}

