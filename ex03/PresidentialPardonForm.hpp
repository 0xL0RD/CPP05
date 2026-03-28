/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:09:03 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/27 13:18:39 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define PP_NAME "presidentialpardon"
# define PP_SIGN_MIN 25
# define PP_EXEC_MIN 5 

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(const PresidentialPardonForm &lhs);
		void	execute_child(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
		PresidentialPardonForm(void);
};

#endif
