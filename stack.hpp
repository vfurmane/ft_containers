/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:26:49 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 15:39:38 by vfurmane         ###   ########.fr       */
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
			typedef Container 							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			stack(const Container& cont = Container()) : c(cont)
			{
			}
			~stack(void)
			{
			}

			reference top()
			{
				return c.back();
			}
			const_reference top() const
			{
				return c.back();
			}

			bool empty() const
			{
				return c.empty();
			}

			size_type size() const
			{
				return c.size();
			}

			void push(const value_type& value)
			{
				c.push_back(value);
			}

			void pop()
			{
				c.pop_back();
			}

			template<class T1, class Container1>
			friend bool	operator==(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs );
			template<class T1, class Container1>
			friend bool	operator<(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs );
	
		protected:
			Container	c;
	};

	template<class T1, class Container1>
	bool	operator==(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs )
	{
		return lhs.c == rhs.c;
	}
	template<class T1, class Container1>
	bool	operator!=(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs )
	{
		return !(lhs == rhs);
	}
	template<class T1, class Container1>
	bool	operator<(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs )
	{
		return lhs.c < rhs.c;
	}
	template<class T1, class Container1>
	bool	operator<=(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs )
	{
		return !(lhs > rhs);
	}
	template<class T1, class Container1>
	bool	operator>(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs )
	{
		return rhs < lhs;
	}
	template<class T1, class Container1>
	bool	operator>=(const ft::stack<T1,Container1>& lhs, const ft::stack<T1,Container1>& rhs )
	{
		return !(lhs < rhs);
	}

}

#endif
