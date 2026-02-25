/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:13 by rubsanch          #+#    #+#             */
/*   Updated: 2026/02/25 17:51:36 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <ofstream>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define SH_NAME "shrubbery"
# define SH_SIGN_MIN 145
# define SH_EXEC_MIN 137

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &lhs);

		void	execute_child(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
		ShrubberyCreationForm(void);
};
#endif
