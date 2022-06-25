/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:32:27 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 13:44:01 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# ifdef USE_STD
#  include <stack>
# else
#  include "stack.hpp"
# endif

template<typename T, typename Container>
class MutantStack : public NAMESPACE::stack<T, Container>
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator		begin()
		{
			return this->c.begin();
		}
		const_iterator	begin() const
		{
			return this->c.begin();
		}
		iterator		end()
		{
			return this->c.end();
		}
		const_iterator	end() const
		{
			return this->c.end();
		}
};

#endif
