/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:26:49 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/23 11:41:29 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container 						container_type;
			typedef typename Container::value_type	value_type;

			stack(const Container& cont = Container()) : c(cont)
			{
			}
			~stack(void)
			{
			}
	
		protected:
			Container	c;
	};
}

#endif
