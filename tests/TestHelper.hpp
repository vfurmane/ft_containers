/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelper.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:46:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/22 21:04:40 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>

#ifndef TEST_HELPER_HPP
# define TEST_HELPER_HPP

typedef enum	helper_mode
{
	NORMAL
}				e_helper_mode;

template <e_helper_mode Mode = NORMAL, class T = int>
class TestHelper
{
	public:
		typedef TestHelper reference;
		typedef TestHelper const_reference;
		typedef TestHelper pointer;
		typedef TestHelper const_pointer;

		TestHelper(void) : nbr(42), ptr(new T)
		{
			std::cout << "Default constructor" << std::endl;
			*ptr = 21;
		}
		TestHelper(T nbr) : nbr(nbr), ptr(new T)
		{
			std::cout << "Default constructor" << std::endl;
			*ptr = 21;
		}
		TestHelper(TestHelper const &src) : nbr(src.nbr), ptr(new T)
		{
			std::cout << "Copy constructor" << std::endl;
			*ptr = *src.ptr;
		}
		~TestHelper(void)
		{
			std::cout << "Destructor" << std::endl;
			delete ptr;
			std::cout << "Done destructor" << std::endl;
		}

		TestHelper	operator=(const TestHelper &rhs)
		{
			nbr = rhs.nbr;
			*ptr = *rhs.ptr;
			return *this;
		}

		void greet(void) const
		{
			std::cout << "greetings" << std::endl;
		}
		
		T	nbr;
		T	*ptr;
};

std::ostream	&operator<<(std::ostream &os, const TestHelper<> &rhs)
{
	os << "(nbr : " << rhs.nbr << ", ptr : " << *rhs.ptr << ")";
	return os;
}

#endif
