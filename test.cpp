/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:32:02 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 15:03:44 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
# include <vector>

// Default value for the USE_STD macro
#ifndef USE_STD
# define USE_STD 0
#endif

// Select the namespace to use
#if USE_STD == 0
# define NAMESPACE ft
# include "iterator.hpp"
# include "type_traits.hpp"
# include "vector.hpp"
#else
# define NAMESPACE std
# include <vector>
#endif

#include <iostream>
#include <typeinfo>

template <class T, typename size_type>
void print_container_access_operator(const T &obj, size_type n)
{
	std::cout << " { ";
	for (size_type i = 0; i < n; i++)
		std::cout << obj[i] << (i < n - 1 ? ", " : "");
	std::cout << " }" << std::endl;
}

template <class T, typename size_type>
void print_container_at(const T &obj, size_type n)
{
	std::cout << " { ";
	for (size_type i = 0; i < n; i++)
		std::cout << obj.at(i) << (i < n - 1 ? ", " : "");
	std::cout << " }" << std::endl;
}

template <class Iterator>
void print_container_iter(Iterator begin, Iterator end)
{
	std::cout << " { ";
	while (begin != end)
	{
		std::cout << *begin << (begin < end - 1 ? ", " : "");
		begin++;
	}
	std::cout << " }" << std::endl;
}

void	integral_contant_testing(void)
{
	std::cout << "========== INTEGRAL CONSTANT ==========" << std::endl;
	std::cout << "Member types" << std::endl;
	{
		std::cout << " value_type <bool, true> == bool : ";
		if (typeid(NAMESPACE::integral_constant<bool, true>::value_type) == typeid(bool))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " value_type <int, 42> == int     : ";
		if (typeid(NAMESPACE::integral_constant<int, 42>::value_type) == typeid(int))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " type <bool, true>               : ";
		if (typeid(NAMESPACE::integral_constant<bool, true>::type) == typeid(NAMESPACE::integral_constant<bool, true>))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " type <int, 42>                  : ";
		if (typeid(NAMESPACE::integral_constant<int, 42>::type) == typeid(NAMESPACE::integral_constant<int, 42>))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << "Member constants" << std::endl;
	{
		std::cout << " value <bool, true>              : ";
		std::cout << NAMESPACE::integral_constant<bool, true>::value << std::endl;
	}
	{
		std::cout << " value <bool, false>             : ";
		std::cout << NAMESPACE::integral_constant<bool, false>::value << std::endl;
	}
	{
		std::cout << " value <int, 42>                 : ";
		std::cout << NAMESPACE::integral_constant<int, 42>::value << std::endl;
	}
	std::cout << "Member functions" << std::endl;
	{
		std::cout << " value_type() <bool, true>       : ";
		NAMESPACE::integral_constant<bool, true> obj;
		std::cout << static_cast<bool>(obj) << std::endl;
	}
	{
		std::cout << " value_type() <bool, false>      : ";
		NAMESPACE::integral_constant<bool, false> obj;
		std::cout << static_cast<bool>(obj) << std::endl;
	}
	{
		std::cout << " value_type() <int, 42>          : ";
		NAMESPACE::integral_constant<int, 42> obj;
		std::cout << static_cast<int>(obj) << std::endl;
	}
	std::cout << "Instantiations" << std::endl;
	{
		std::cout << " true_type                       : ";
		if (typeid(NAMESPACE::integral_constant<bool, true>) == typeid(NAMESPACE::true_type))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " false_type                      : ";
		if (typeid(NAMESPACE::integral_constant<bool, false>) == typeid(NAMESPACE::false_type))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
}

void	is_integral_testing(void)
{
	std::cout << "============= IS_INTEGRAL =============" << std::endl;
	std::cout << "Member types" << std::endl;
	{
		std::cout << " value_type == bool             : ";
		if (typeid(NAMESPACE::is_integral<int>::value_type) == typeid(bool))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << "Member constants" << std::endl;
	{
		std::cout << " value <double>                 : ";
		std::cout << NAMESPACE::is_integral<double>::value << std::endl;
	}
	{
		std::cout << " value <bool>                   : ";
		std::cout << NAMESPACE::is_integral<bool>::value << std::endl;
	}
	{
		std::cout << " value <char>                   : ";
		std::cout << NAMESPACE::is_integral<char>::value << std::endl;
	}
	{
		std::cout << " value <wchar_t>                : ";
		std::cout << NAMESPACE::is_integral<wchar_t>::value << std::endl;
	}
	{
		std::cout << " value <signed char>            : ";
		std::cout << NAMESPACE::is_integral<signed char>::value << std::endl;
	}
	{
		std::cout << " value <short int>              : ";
		std::cout << NAMESPACE::is_integral<short int>::value << std::endl;
	}
	{
		std::cout << " value <int>                    : ";
		std::cout << NAMESPACE::is_integral<int>::value << std::endl;
	}
	{
		std::cout << " value <long int>               : ";
		std::cout << NAMESPACE::is_integral<long int>::value << std::endl;
	}
	{
		std::cout << " value <long long int>          : ";
		std::cout << NAMESPACE::is_integral<long long int>::value << std::endl;
	}
	{
		std::cout << " value <unsigned char>          : ";
		std::cout << NAMESPACE::is_integral<unsigned char>::value << std::endl;
	}
	{
		std::cout << " value <unsigned short int>     : ";
		std::cout << NAMESPACE::is_integral<unsigned short int>::value << std::endl;
	}
	{
		std::cout << " value <unsigned int>           : ";
		std::cout << NAMESPACE::is_integral<unsigned int>::value << std::endl;
	}
	{
		std::cout << " value <unsigned long int>      : ";
		std::cout << NAMESPACE::is_integral<unsigned long int>::value << std::endl;
	}
	{
		std::cout << " value <unsigned long long int> : ";
		std::cout << NAMESPACE::is_integral<unsigned long long int>::value << std::endl;
	}
	std::cout << "Member functions" << std::endl;
	{
		std::cout << " value_type() <double>          : ";
		NAMESPACE::is_integral<double> obj;
		std::cout << static_cast<bool>(obj) << std::endl;
	}
	{
		std::cout << " value_type() <bool>            : ";
		NAMESPACE::is_integral<bool> obj;
		std::cout << static_cast<bool>(obj) << std::endl;
	}
	{
		std::cout << " value_type() <int>             : ";
		NAMESPACE::is_integral<int> obj;
		std::cout << static_cast<bool>(obj) << std::endl;
	}
}

void iterator_testing(void)
{
	std::cout << "============= ITERATOR =============" << std::endl;
	std::cout << "Member types" << std::endl;
	{
		std::cout << " value_type : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::value_type) == typeid(int))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " difference_type : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::difference_type) == typeid(std::ptrdiff_t))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " difference_type (set to float) : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, float>::difference_type) == typeid(float))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " pointer : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::pointer) == typeid(int *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " pointer (set to float *) : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, std::ptrdiff_t, float *>::pointer) == typeid(float *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " reference : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::reference) == typeid(int &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " reference (set to float *) : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, std::ptrdiff_t, int *, float &>::reference) == typeid(float &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " iterator_category : ";
		if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::iterator_category) == typeid(NAMESPACE::random_access_iterator_tag))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
}

void iterator_traits_testing(void)
{
	std::cout << "========== ITERATOR TRAITS =========" << std::endl;
	std::cout << "Member types" << std::endl;
	{
		std::cout << " difference_type : ";
		if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, float> >::difference_type) == typeid(float))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " difference_type (T *) : ";
		if (typeid(NAMESPACE::iterator_traits<int *>::difference_type) == typeid(std::ptrdiff_t))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " difference_type (const T *) : ";
		if (typeid(NAMESPACE::iterator_traits<const int *>::difference_type) == typeid(std::ptrdiff_t))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " value_type : ";
		if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int> >::value_type) == typeid(int))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " value_type (T *) : ";
		if (typeid(NAMESPACE::iterator_traits<int *>::value_type) == typeid(int))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " value_type (const T *) : ";
		if (typeid(NAMESPACE::iterator_traits<const int *>::value_type) == typeid(int))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " pointer : ";
		if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int> >::pointer) == typeid(int *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " pointer (T *) : ";
		if (typeid(NAMESPACE::iterator_traits<int *>::pointer) == typeid(int *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " pointer (const T *) : ";
		if (typeid(NAMESPACE::iterator_traits<const int *>::pointer) == typeid(const int *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " reference : ";
		if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int> >::reference) == typeid(int &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " reference (T *) : ";
		if (typeid(NAMESPACE::iterator_traits<int *>::reference) == typeid(int &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " reference (const T *) : ";
		if (typeid(NAMESPACE::iterator_traits<const int *>::reference) == typeid(const int &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " iterator_category : ";
		if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::output_iterator_tag, int> >::iterator_category) == typeid(NAMESPACE::output_iterator_tag))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " iterator_category (T *) : ";
		if (typeid(NAMESPACE::iterator_traits<int *>::iterator_category) == typeid(NAMESPACE::random_access_iterator_tag))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " iterator_category (const T *) : ";
		if (typeid(NAMESPACE::iterator_traits<const int *>::iterator_category) == typeid(NAMESPACE::random_access_iterator_tag))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
}

class TestHelper
{
	public:
		typedef TestHelper reference;
		typedef TestHelper const_reference;
		typedef TestHelper pointer;
		typedef TestHelper const_pointer;

		TestHelper(void) : nbr(42), ptr(new int)
		{
			*ptr = 21;
		}
		TestHelper(TestHelper const &src) : nbr(src.nbr), ptr(new int)
		{
			std::cout << "Copy constructor" << std::endl;
			*ptr = *src.ptr;
		}
		~TestHelper(void)
		{
			delete ptr;
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

void	reverse_iterator_testing(void)
{
	std::cout << "========= REVERSE ITERATOR =========" << std::endl;
	std::cout << "Constructors" << std::endl;
	{
		NAMESPACE::reverse_iterator<NAMESPACE::vector<int>::iterator>	obj;
		std::cout << " (void) : OK" << std::endl;
	}
	{
		NAMESPACE::vector<int>::iterator								src;
		NAMESPACE::reverse_iterator<NAMESPACE::vector<int>::iterator>	obj(src);
		std::cout << " (iterator_type) : OK" << std::endl;
	}
	{
		NAMESPACE::vector<int>::iterator								src;
		NAMESPACE::reverse_iterator<NAMESPACE::vector<int>::iterator>	obj(src);
		std::cout << " (const reverse_iterator<Iter> &) : OK" << std::endl;
	}
	std::cout << "Methods" << std::endl;
	{
		std::cout << " base()" << std::endl;
		NAMESPACE::vector<int>::iterator 								src;
		NAMESPACE::reverse_iterator<NAMESPACE::vector<int>::iterator>	obj(src);
		std::cout << "src is ";
		if (src != obj.base())
			std::cout << "not ";
		std::cout << "equal to obj.base()" << std::endl;
	}
	{
		std::cout << " *x operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	src(&nbr[1]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " *x operator (with end()) : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int> src(&nbr[0], &nbr[2]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src.end());
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " x + n operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	src(&nbr[2]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(obj + 1) << " - ";
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " ++x operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(++obj) << " - ";
		std::cout << *(++obj) << std::endl;
	}
	{
		std::cout << " x++ operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(obj++) << " - ";
		std::cout << *(obj++) << std::endl;
	}
	{
		std::cout << " x += n operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	src(&nbr[2]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(obj += 1) << " - ";
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " x - n operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	src(&nbr[1]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(obj - 1) << " - ";
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " --x operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[1]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(--obj) << " - ";
		std::cout << *(--obj) << std::endl;
	}
	{
		std::cout << " x-- operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[1]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(obj--) << " - ";
		std::cout << *(obj--) << std::endl;
	}
	{
		std::cout << " x -= n operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	src(&nbr[1]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(obj -= 1) << " - ";
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " x->n operator : ";
		TestHelper	test_helper;
		NAMESPACE::vector<TestHelper>::iterator	src(&test_helper);
		NAMESPACE::vector<TestHelper>::reverse_iterator	obj(src);
		obj->greet();
	}
	{
		std::cout << " x[n] operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << obj[1] << std::endl;
	}
	{
		std::cout << " x == y operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 == obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x == y operator (with copy) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(obj1);
		if (obj1 == obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x == y operator (false) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src - 1);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 == obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x != y operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1++;
		if (obj1 != obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x != y operator (with copy) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(obj1);
		obj1++;
		if (obj1 != obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x != y operator (false) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 != obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x < y operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1--;
		if (obj1 < obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x < y operator (with copy) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(obj1);
		obj1--;
		if (obj1 < obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x < y operator (false ==) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 < obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x < y operator (false >) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1++;
		if (obj1 < obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x <= y operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1--;
		if (obj1 <= obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x <= y operator (with copy) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(obj1);
		obj1--;
		if (obj1 <= obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x <= y operator (is equal) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 <= obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x <= y operator (false >) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1++;
		if (obj1 <= obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x > y operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1++;
		if (obj1 > obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x < y operator (with copy) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(obj1);
		obj1++;
		if (obj1 > obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x < y operator (false ==) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 > obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x < y operator (false >) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1--;
		if (obj1 > obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " x <= y operator : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1++;
		if (obj1 >= obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x <= y operator (with copy) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(obj1);
		obj1++;
		if (obj1 >= obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x <= y operator (is equal) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		if (obj1 >= obj2)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " x <= y operator (false >) : ";
		int	nbr[] = {42, 21, 1337, 125};
		NAMESPACE::vector<int>::iterator	src(&nbr[3]);
		NAMESPACE::vector<int>::reverse_iterator	obj1(src);
		NAMESPACE::vector<int>::reverse_iterator	obj2(src);
		obj1--;
		if (obj1 >= obj2)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	{
		std::cout << " n + x operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	src(&nbr[2]);
		NAMESPACE::vector<int>::reverse_iterator	obj(src);
		std::cout << *(1 + obj) << " - ";
		std::cout << *obj << std::endl;
	}
	{
		std::cout << " x - y operator : ";
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
		NAMESPACE::vector<int>::iterator	obj2(&nbr[2]);
		std::cout << obj - obj2 << " | ";
		std::cout << obj - obj1 << " | ";
		std::cout << obj - obj << " | ";
		std::cout << obj1 - obj << " | ";
		std::cout << obj2 - obj << std::endl;
	}
}

void	vector_testing(void)
{
	std::cout << "============== VECTOR ==============" << std::endl;
	std::cout << "with ints               : OK" << std::endl;
	std::cout << "with allocator          : OK" << std::endl;
	std::cout << "Member types" << std::endl;
	{
		std::cout << " value_type             : ";
		if (typeid(NAMESPACE::vector<TestHelper>::value_type) == typeid(TestHelper))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " allocator_type         : ";
		if (typeid(NAMESPACE::vector< TestHelper, std::allocator<TestHelper> >::allocator_type::value_type) == typeid(TestHelper))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " reference              : ";
		if (typeid(NAMESPACE::vector<TestHelper>::reference) == typeid(TestHelper &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " const_reference        : ";
		if (typeid(NAMESPACE::vector<TestHelper>::const_reference) == typeid(const TestHelper &))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " pointer                : ";
		if (typeid(NAMESPACE::vector<TestHelper>::pointer) == typeid(TestHelper *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		std::cout << " const_pointer          : ";
		if (typeid(NAMESPACE::vector<TestHelper>::const_pointer) == typeid(const TestHelper *))
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::iterator var;
		(void)var;
		std::cout << " iterator               : exists" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::const_iterator var;
		(void)var;
		std::cout << " const_iterator         : exists" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::reverse_iterator var;
		(void)var;
		std::cout << " reverse_iterator       : exists" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::const_reverse_iterator var;
		(void)var;
		std::cout << " const_reverse_iterator : exists" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::difference_type var;
		(void)var;
		std::cout << " difference_type        : exists" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::size_type var;
		(void)var;
		std::cout << " size_type              : exists" << std::endl;
	}
	std::cout << "Constructors" << std::endl;
	{
		NAMESPACE::vector<int> obj;
		(void)obj;
		std::cout << " (void)                          : OK" << std::endl;
	}
	{
		std::allocator<int> alloc;
		NAMESPACE::vector<int> obj(alloc);
		(void)obj;
		std::cout << " (const allocator_type&)         : OK" << std::endl;
	}
	{
		NAMESPACE::vector<int> obj(5);
		(void)obj;
		std::cout << " (size_type)                     : OK" << std::endl;
	}
	{
		NAMESPACE::vector<int> obj(5, 0);
		(void)obj;
		std::cout << " (size_type," << std::endl;
		std::cout << "  const value_type&)             : OK" << std::endl;
	}
	{
		std::allocator<int> alloc;
		NAMESPACE::vector<int> obj(5, 0, alloc);
		(void)obj;
		std::cout << " (size_type," << std::endl;
		std::cout << "  const value_type&," << std::endl;
		std::cout << "  const allocator_type&)         : OK" << std::endl;
	}
	{
		int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " (InputIterator," << std::endl;
		std::cout << "  InputIterator) <int *>         : OK" << std::endl;
		print_container_access_operator(obj, 5);
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " (const InputIterator," << std::endl;
		std::cout << "  const InputIterator) <int *>   : OK" << std::endl;
		print_container_access_operator(obj, 5);
	}
	{
		int arr[5] = {1, 2, 3, 4, 5};
		std::vector<int> src(arr, arr + (sizeof (arr) / sizeof (*arr)));
		NAMESPACE::vector<int> obj(src.begin(), src.end());
		std::cout << " (InputIterator," << std::endl;
		std::cout << "  InputIterator) <iterator>      : OK" << std::endl;
		print_container_access_operator(obj, 5);
	}
	{
		std::allocator<int> alloc;
		int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)), alloc);
		std::cout << " (InputIterator," << std::endl;
		std::cout << "  InputIterator," << std::endl;
		std::cout << "  const allocator_type&) <int *> : OK" << std::endl;
		print_container_access_operator(obj, 5);
	}
	{
		NAMESPACE::vector<int> obj(5, 0);
		NAMESPACE::vector<int> copy(obj);
		(void)copy;
		std::cout << " (const vector &)                : OK" << std::endl;
	}
	std::cout << "begin() and end()" << std::endl;
	{
		int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> src(arr, arr + (sizeof (arr) / sizeof (*arr)));
		print_container_iter(src.begin(), src.end());
	}
	std::cout << "rbegin() and rend()" << std::endl;
	{
		int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> src(arr, arr + (sizeof (arr) / sizeof (*arr)));
		print_container_iter(src.rbegin(), src.rend());
	}
	std::cout << "size()" << std::endl;
	{
		NAMESPACE::vector<int> src(5, 0);
		std::cout << " with five zeros : " << src.size() << std::endl;
	}
	{
		const int src[7] = {1, 2, 3, 4, 5, 6, 7};
		NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
		std::cout << " with int[7]     : " << obj.size() << std::endl;
	}
	std::cout << "max_size()" << std::endl;
	{
		NAMESPACE::vector<int> src;
		std::cout << " <int>    : " << src.max_size() << std::endl;
	}
	{
		NAMESPACE::vector<double> src;
		std::cout << " <double> : " << src.max_size() << std::endl;
	}
	std::cout << "resize()" << std::endl;
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(0);
		std::cout << " size : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<TestHelper> obj(3);
		obj.resize(0);
		obj.push_back(TestHelper());
		std::cout << " size : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(3);
		std::cout << " size : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(5);
		std::cout << " size : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(8);
		std::cout << " size : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "capacity()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5, 0);
		std::cout << " size     : " << obj.size() << std::endl;
		std::cout << " capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5, 0);
		obj.resize(16, 3);
		std::cout << " size     : " << obj.size() << std::endl;
		std::cout << " capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5, 0);
		obj.resize(3, 3);
		std::cout << " size     : " << obj.size() << std::endl;
		std::cout << " capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "empty()" << std::endl;
	{
		NAMESPACE::vector<int> obj;
		std::cout << " is ";
		if (obj.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "not empty" << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(0);
		std::cout << " is ";
		if (obj.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "not empty" << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		std::cout << " is ";
		if (obj.empty())
			std::cout << "empty" << std::endl;
		else
			std::cout << "not empty" << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "reserve()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5);
		obj.reserve(3);
		std::cout << " capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.reserve(5);
		std::cout << " capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.reserve(16);
		std::cout << " capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "capacity()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5, 0);
		std::cout << obj.capacity() << std::endl;
	}
	{
		NAMESPACE::vector<int> obj(5, 0);
		obj.resize(16, 3);
		std::cout << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5, 0);
		obj.resize(3, 3);
		std::cout << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "Assignation operator" << std::endl;
	{
		NAMESPACE::vector<int> src(5, 0);
		print_container_access_operator(src, 5);
	}
	{
		NAMESPACE::vector<int> src(5, 0);
		NAMESPACE::vector<int> copy = src;
		src[2] = 6;
		copy[2] = 7;
		print_container_access_operator(src, 5);
		print_container_access_operator(copy, 5);
	}
	std::cout << "at()" << std::endl;
	{
		NAMESPACE::vector<int> src(5, 0);
		print_container_at(src, 5);
	}
	{
		NAMESPACE::vector<int> src(5, 0);
		NAMESPACE::vector<int> copy = src;
		src.at(2) = 6;
		copy.at(2) = 7;
		print_container_at(src, 5);
		print_container_at(copy, 5);
	}
	{
		NAMESPACE::vector<int> src(5, 0);
		std::cout << " at(4) >> ";
		try {
			src.at(5) = 6;
			std::cout << "Did not throw" << std::endl;
		} catch (std::exception &error) {
			std::cout << "Did throw" << std::endl;
		}
	}
	{
		NAMESPACE::vector<int> src(5, 0);
		std::cout << " at(5) >> ";
		try {
			src.at(5) = 6;
			std::cout << "Did not throw" << std::endl;
		} catch (std::exception &error) {
			std::cout << "Did throw" << std::endl;
		}
	}
	std::cout << "front()" << std::endl;
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " front() == " << obj.front() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.front() = 6;
		std::cout << " front() == " << obj.front() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "back()" << std::endl;
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " back() == " << obj.back() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.back() = 6;
		std::cout << " back() == " << obj.back() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "assign()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5);
		obj.assign(4, 2);
		std::cout << " size     : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.assign(5, 2);
		std::cout << " size     : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.assign(6, 2);
		std::cout << " size     : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int src[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
		const int arr[4] = {5, 4, 3, 2};
		obj.assign(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " size     : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int src[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
		const int arr[5] = {5, 4, 3, 2, 1};
		obj.assign(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " size     : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int src[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
		const int arr[6] = {6, 5, 4, 3, 2, 1};
		obj.assign(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " size     : " << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	std::cout << "push_back()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5);
		obj.push_back(42);
		std::cout << " >> 42" << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		std::cout << "back     : " << obj.back() << std::endl;
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.reserve(6);
		obj.push_back(42);
		std::cout << " >> 42" << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		std::cout << "back     : " << obj.back() << std::endl;
	}
	{
		NAMESPACE::vector<int> obj;
		obj.push_back(42);
		std::cout << " >> 42" << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		std::cout << "back     : " << obj.back() << std::endl;
	}
	std::cout << "pop_back()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5);
		obj.pop_back();
		std::cout << " <<" << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		std::cout << "back     : " << obj.back() << std::endl;
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.push_back(42);
		obj.pop_back();
		std::cout << " <<" << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		std::cout << "back     : " << obj.back() << std::endl;
	}
	{
		NAMESPACE::vector<int> obj(5);
		obj.push_back(42);
		obj.pop_back();
		obj.push_back(42);
		std::cout << " <<" << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		std::cout << "back     : " << obj.back() << std::endl;
	}
	std::cout << "insert()" << std::endl;
	{
		NAMESPACE::vector<int> obj(5);
		NAMESPACE::vector<int>::iterator pos = obj.insert(obj.begin(), 42);
		std::cout << "position : " << *pos << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		NAMESPACE::vector<int>::iterator pos = obj.insert(obj.begin() + 2, 42);
		std::cout << "position : " << *pos << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		NAMESPACE::vector<int> obj(5);
		NAMESPACE::vector<int>::iterator pos = obj.insert(obj.end(), 42);
		std::cout << "position : " << *pos << std::endl;
		std::cout << "size     : " << obj.size() << std::endl;
		std::cout << "capacity : " << obj.capacity() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
}

void vector_random_access_iterator_testing(void)
{
	std::cout << "====== RANDOM ACCESS ITERATOR ======" << std::endl;
	std::cout << " default constructor: ";
	{
		NAMESPACE::vector<int>::iterator	obj;
		(void)obj;
		std::cout << "OK" << std::endl;
	}
	std::cout << " copy constructor: ";
	{
		NAMESPACE::vector<int>::iterator	src;
		NAMESPACE::vector<int>::iterator	obj(src);
		(void)obj;
		std::cout << "OK" << std::endl;
	}
	std::cout << " assign operator: ";
	{
		NAMESPACE::vector<int>::iterator	src;
		NAMESPACE::vector<int>::iterator	obj = src;
		(void)obj;
		std::cout << "OK" << std::endl;
	}
	std::cout << " == operator: ";
	{
		NAMESPACE::vector<int>::iterator	src;
		NAMESPACE::vector<int>::iterator	obj(src);
		if (obj == src)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " != operator: ";
	{
		NAMESPACE::vector<int>::iterator	src;
		NAMESPACE::vector<int>::iterator	obj(src);
		if (obj != src)
			std::cout << "KO" << std::endl;
		else
			std::cout << "OK" << std::endl;
	}
	std::cout << " *x operator: ";
	{
		int	nbr = 42;
		NAMESPACE::vector<int>::iterator	obj(&nbr);
		std::cout << *obj << std::endl;
	}
	std::cout << " x->n operator: ";
	{
		TestHelper	src;
		NAMESPACE::vector<TestHelper>::iterator	obj(&src);
		std::cout << obj->nbr << std::endl;
	}
	std::cout << " *x = operator: ";
	{
		int	nbr = 42;
		NAMESPACE::vector<int>::iterator	obj(&nbr);
		std::cout << (*obj = 21) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " ++x operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		std::cout << *(++obj) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x++ operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		std::cout << *(obj++) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " *x++ operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		std::cout << *obj++ << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " --x operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(&nbr[1]);
		std::cout << *(--obj) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x-- operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(&nbr[1]);
		std::cout << *(obj--) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x + n operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		std::cout << *(obj + 1) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " n + x operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		std::cout << *(1 + obj) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x - n operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(&nbr[1]);
		std::cout << *(obj - 1) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x - y operator: ";
	{
		int	nbr[] = {42, 21, 1337};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
		NAMESPACE::vector<int>::iterator	obj2(&nbr[2]);
		std::cout << obj - obj2 << " | ";
		std::cout << obj - obj1 << " | ";
		std::cout << obj - obj << " | ";
		std::cout << obj1 - obj << " | ";
		std::cout << obj2 - obj << std::endl;
	}
	std::cout << " x < y operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
		if (obj < obj1)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " x > y operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
		if (obj1 > obj)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " x <= y (is inf) operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
		if (obj <= obj1)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " x <= y (is eq) operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(nbr);
		if (obj <= obj1)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " x >= y (is grt) operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
		if (obj1 >= obj)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " x >= y (is eq) operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		NAMESPACE::vector<int>::iterator	obj1(nbr);
		if (obj1 >= obj)
			std::cout << "OK" << std::endl;
		else
			std::cout << "KO" << std::endl;
	}
	std::cout << " x += n operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		std::cout << *(obj += 1) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x -= n operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(&nbr[1]);
		std::cout << *(obj -= 1) << " | ";
		std::cout << *obj << std::endl;
	}
	std::cout << " x[n] operator: ";
	{
		int	nbr[] = {42, 21};
		NAMESPACE::vector<int>::iterator	obj(nbr);
		obj[1] = 1337;
		std::cout << obj[0] << " | ";
		std::cout << obj[1] << std::endl;
	}
}

int	main(void)
{
	integral_contant_testing();
	is_integral_testing();
	iterator_testing();
	iterator_traits_testing();
	reverse_iterator_testing();
	vector_testing();
	vector_random_access_iterator_testing();
	return 0;
}
