/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:05:42 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 10:31:47 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
Form::Form(void)
{
	return ;
}
*/

Form::Form(const std::string &name, int signGrade, int execGrade)
	:	_name(name),
		_isSigned(false),
		_signGrade(signGrade),
		_execGrade(execGrade)
{
	checkGrade(signGrade);
	checkGrade(execGrade);
}

Form::Form(const Form &other)
	:	_name(other.getName()),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade)
{
	this->_isSigned = false;	// at construction, it is not
}

Form::~Form(void)
{
	return ;
}
		
Form& Form::operator=(const Form &lhs)
{
	this->_isSigned = lhs.isSigned();
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::isSigned(void) const
{
	return (this->_isSigned);
}

int			Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int			Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void		Form::beSigned(const Bureaucrat &b)
{
	checkGrade(b.getGrade(), this->_signGrade);
	this->_isSigned = true;
}

void	Form::checkGrade(int grade)
{
	checkGrade(grade, BU_GRADE_MIN);
}

void	Form::checkGrade(int grade, int mingrade)
{
	if (grade < BU_GRADE_MAX)
		throw (Form::GradeTooHighException());
	//else if (grade > BU_GRADE_MIN)
	else if (grade > mingrade)
		throw (Form::GradeTooLowException());
	return ;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Form: Grade is too high");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Form: Grade is too low");
}

std::ostream&	operator<<(std::ostream& os, Form &f)
{
	os << f.getName() << ", form is signed: " << f.isSigned() << "; "
		<< "min. sign grade: " << f.getSignGrade() << "; "
		<< "min. exec grade: " << f.getExecGrade();
	return (os);
}
