/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelper.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:46:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 11:34:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HELPER_HPP
# define TEST_HELPER_HPP

class TestHelper
{
	public:
		typedef TestHelper reference;
		typedef TestHelper const_reference;
		typedef TestHelper pointer;
		typedef TestHelper const_pointer;

		TestHelper(void) : nbr(42), ptr(new int)
		{
			std::cout << "Default constructor" << std::endl;
			*ptr = 21;
		}
		TestHelper(int nbr) : nbr(nbr), ptr(new int)
		{
			std::cout << "Default constructor" << std::endl;
			*ptr = 21;
		}
		TestHelper(TestHelper const &src) : nbr(src.nbr), ptr(new int)
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
		
		int	nbr;
		int	*ptr;
};

std::ostream	&operator<<(std::ostream &os, const TestHelper &rhs)
{
	os << "(nbr : " << rhs.nbr << ", ptr : " << *rhs.ptr << ")";
	return os;
}

#endif
