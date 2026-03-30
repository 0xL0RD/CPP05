/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:05:33 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/30 16:40:11 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		static AForm*	makeForm(std::string formName, std::string target);

		static AForm*	newShrubberyCreationForm(std::string &target);
		static AForm*	newPresidentialPardonForm(std::string &target);
		static AForm*	newRobotomyRequestForm(std::string &target);
	
	private:
		Intern(void);
		Intern(const Intern& other);
		~Intern(void);

		Intern&	operator=(const Intern& lhs);
};

#endif
