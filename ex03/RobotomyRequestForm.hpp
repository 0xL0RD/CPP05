/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsanch <rubsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:09:03 by rubsanch          #+#    #+#             */
/*   Updated: 2026/03/27 14:45:16 by rubsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"
# include "AForm.hpp"

# define RR_NAME "robotomy"
# define RR_SIGN_MIN 72 
# define RR_EXEC_MIN 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(const RobotomyRequestForm &lhs);
		void	execute_child(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
		RobotomyRequestForm(void);
};

#endif
