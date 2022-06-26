/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:08:55 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/26 12:04:07 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {
	template<class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1	first;
		T2	second;

		pair(void) : first(), second()
		{
		}
		pair(const T1& x, const T2& y) : first(x), second(y)
		{
		}
		template<class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second)
		{
		}
		~pair(void)
		{
		}

		pair& operator=(const pair& other)
		{
			first = other.first;
			second = other.second;
		}
	};

	template<class T1, class T2>
	ft::pair<T1,T2>	make_pair(T1 t, T2 u)
	{
		return ft::pair<T1, T2>(t, u);
	}
}

#endif
