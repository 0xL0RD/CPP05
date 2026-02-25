/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:28:28 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 10:05:03 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Form.hpp"

# define BU_GRADE_MIN 150
# define BU_GRADE_MAX 1

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);

		Bureaucrat& operator=(const Bureaucrat &lhs);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		setGrade(int grade);

		void		signForm(Form &form) const;

		class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};
		class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream &os, Bureaucrat &b);

#endif
