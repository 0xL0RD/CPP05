/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:23:56 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/28 10:29:43 by rubsanch         ###   ########.fr       */
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
	this->AForm::operator=(lhs);
	return (*this);
}

void	ShrubberyCreationForm::execute_child(Bureaucrat const & executor) const
{
	(void) executor;
	std::string	fileName = this->_target + "_" + SH_NAME;
	std::string	trees =
		"      *         *     \n"
		"     ***       ***    \n"
		"    *****     *****   \n"
		"   *******   *******  \n"
		"      ||        ||    \n";
	std::ofstream myfile(fileName.c_str());
	myfile.write(trees.c_str(), trees.size());
	myfile.close();
}
