/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 07:00:05 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 10:14:35 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const Form &other);
		Form(const std::string &name, int signGrade, int execGrade);
		~Form(void);
		
		Form& operator=(const Form &lhs);

		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		void		beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
	{
			public:
				virtual const char* what(void) const throw();
	};
		class GradeTooLowException : public std::exception
	{
				virtual const char* what(void) const throw();
	};
	
	protected:
		void	checkGrade(int grade);
		void	checkGrade(int grade, int mingrade);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		Form(void);
};

std::ostream&	operator<<(std::ostream& os, Form &f);

#endif
