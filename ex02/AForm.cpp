/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:05:42 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 17:57:38 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
{
	return ;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	:	_name(name),
		_isSigned(false),
		_signGrade(signGrade),
		_execGrade(execGrade)
{
	checkGrade(signGrade);
	checkGrade(execGrade);
}

AForm::AForm(const AForm &other)
	:	_name(other.getName()),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade)
{
	this->_isSigned = false;	// at construction, it is not
}

AForm::~AForm(void)
{
	return ;
}
		
AForm& AForm::operator=(const AForm &lhs)
{
	this->_isSigned = lhs.isSigned();
	return (*this);
}

void	AForm::execute(Bureaucrat const & executor) const
{
	checkGrade(executor.getGrade(), this->_execGrade);
	checkIsSigned();
	this->execute_child(executor);
}

void	AForm::checkIsSigned(void)
{
	if (this->_isSigned == false)
		throw (AForm::FormNotSigned());
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int			AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int			AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void		AForm::beSigned(const Bureaucrat &b)
{
	checkGrade(b.getGrade(), this->_signGrade);
	this->_isSigned = true;
}

void	AForm::checkGrade(int grade)
{
	checkGrade(grade, BU_GRADE_MIN);
}

void	AForm::checkGrade(int grade, int mingrade)
{
	if (grade < BU_GRADE_MAX)
		throw (AForm::GradeTooHighException());
	else if (grade > mingrade)
		throw (AForm::GradeTooLowException());
	return ;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm: Grade is too high");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm: Grade is too low");
}

const char*	AForm::FormNotSigned::what(void) const throw()
{
	return ("AForm: Form is not signed");
}

std::ostream&	operator<<(std::ostream& os, AForm &f)
{
	os << f.getName() << ", form is signed: " << f.isSigned() << "; "
		<< "min. sign grade: " << f.getSignGrade() << "; "
		<< "min. exec grade: " << f.getExecGrade();
	return (os);
}
