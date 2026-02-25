/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:38:00 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 10:15:10 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:	_name("default_name")
{
	this->setGrade(1);
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	:	_name(other.getName())
{
	this->setGrade(other.getGrade());
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:	_name(name)
{
	this->setGrade(grade);
}

Bureaucrat::~Bureaucrat(void)
{
	return ;
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat &lhs)
{
	this->setGrade(lhs.getGrade());
	return (*this);
}


std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::incrementGrade(void)
{
	setGrade(this->_grade - 1);
}

void		Bureaucrat::decrementGrade(void)
{
	setGrade(this->_grade + 1);
}

void		Bureaucrat::setGrade(int grade)
{
	if (grade > BU_GRADE_MIN)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < BU_GRADE_MAX)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

void		Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed "
			<< form.getName()
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign "
			<< form.getName() << " because "
			<< e.what()
			<< std::endl;
	}
}

std::ostream&	operator<<(std::ostream &os, Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
