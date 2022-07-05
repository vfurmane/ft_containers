/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelper.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:46:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/26 21:40:54 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>

#ifndef TEST_HELPER_HPP
# define TEST_HELPER_HPP

typedef enum	helper_mode
{
	NORMAL,
	STACK,
	COMPARE
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

template <class T>
class TestHelper<STACK, T>
{
	public:
		typedef TestHelper pointer;
		typedef TestHelper const_pointer;
		typedef	T		value_type;
		typedef	size_t	size_type;
		typedef	T		&reference;
		typedef	const T	&const_reference;

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

    	bool	empty(void) const
		{
			std::cout << "Calling empty" << std::endl;
			return false;
		}
		
		size_type	size(void) const
		{
			std::cout << "Calling size" << std::endl;
			return 42;
		};

		reference back()
		{
			std::cout << "Calling back" << std::endl;
			return this->nbr;
		}
		const_reference back() const
		{
			std::cout << "Calling const back" << std::endl;
			return this->nbr;
		}

    	void	push_back(void)
		{
			std::cout << "Calling push_back" << std::endl;
		}

    	void	pop_back(void)
		{
			std::cout << "Calling pop_back" << std::endl;
		}
		
		T	nbr;
		T	*ptr;
};

template <class T>
class TestHelper<COMPARE, T>
{
	public:

		TestHelper(void) : nbr(42), ptr(new T)
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

		bool	operator()(const T &lhs, const T &rhs)
		{
			(void)lhs;
			(void)rhs;
			return true;
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
