/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:23:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 19:41:46 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
	:	AForm(SH_NAME, SH_SIGN_MIN, SH_EXEC_MIN),
		_target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	:	AForm(other),
		_target(other._target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
		const ShrubberyCreationForm &lhs
		)
{
	this->Form::operator=(lhs);
}

void	ShrubberyCreationForm::execute_child(Bureaucrat const & executor) const
{
	//this->checkGrade(executor.getGrade(), SH_EXEC_MIN);
	std::string	trees =
		"      *         *     \n"
		"     ***       ***    \n"
		"    *****     *****   \n"
		"   *******   *******  \n"
		"      ||        ||    \n";
	std::ofstream file(this->_target + SH_NAME);
	file.write(trees.c_str(), trees.size());
	file.close();
}
