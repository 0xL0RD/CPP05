/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 07:00:05 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 17:52:58 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const AForm &other);
		AForm(const std::string &name, int signGrade, int execGrade);
		~AForm(void);
		
		AForm& operator=(const AForm &lhs);

		void			execute(Bureaucrat const & executor) const;
		virtual void	execute_child(Bureaucrat const &executor) const = 0;

		std::string		getName(void) const;
		bool			isSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		void			beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
	{
			public:
				virtual const char* what(void) const throw();
	};
		class GradeTooLowException : public std::exception
			public:
	{
				virtual const char* what(void) const throw();
	};
		class FormNotSigned : public std::exception
			public:
	{
				virtual const char* what(void) const throw();
	};
	
	protected:
		void	checkGrade(int grade);
		void	checkGrade(int grade, int mingrade);
		void	checkIsSigned(void);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		AForm(void);
};

std::ostream&	operator<<(std::ostream& os, AForm &f);

#endif
