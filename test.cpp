/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:32:02 by vfurmane          #+#    #+#             */
/*   Updated: 2022/04/12 11:28:44 by vfurmane         ###   ########.fr       */
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
# include "type_traits.hpp"
# include "vector.hpp"
#else
# define NAMESPACE std
#endif

#include <iostream>
#include <typeinfo>

template <class T, typename size_type>
void print_container_access_operator(T obj, size_type n)
{
	std::cout << " { ";
	for (size_type i = 0; i < n; i++)
		std::cout << obj[i] << (i < n - 1 ? ", " : "");
	std::cout << " }" << std::endl;
}

template <class T, typename size_type>
void print_container_at(T obj, size_type n)
{
	std::cout << " { ";
	for (size_type i = 0; i < n; i++)
		std::cout << obj.at(i) << (i < n - 1 ? ", " : "");
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

class TestHelper
{
	public:
		typedef TestHelper reference;
		typedef TestHelper const_reference;
		typedef TestHelper pointer;
		typedef TestHelper const_pointer;

		TestHelper(void)
		{
		}
		void greet(void) const
		{
			std::cout << "greetings" << std::endl;
		}
};

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
		if (typeid(NAMESPACE::vector< int, std::allocator<TestHelper> >::allocator_type::value_type) == typeid(TestHelper))
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
		std::cout << " difference_type        : not working yet" << std::endl;
	}
	{
		NAMESPACE::vector<TestHelper>::size_type var;
		(void)var;
		std::cout << " size_type              : not working yet" << std::endl;
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
	std::cout << "size()" << std::endl;
	{
		NAMESPACE::vector<int> src(5, 0);
		std::cout << src.size() << std::endl;
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " >> " << obj.size() << std::endl;
	}
	std::cout << "max_size()" << std::endl;
	{
		NAMESPACE::vector<int> src;
		std::cout << src.max_size() << std::endl;
	}
	{
		NAMESPACE::vector<double> src;
		std::cout << src.max_size() << std::endl;
	}
	std::cout << "resize()" << std::endl;
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(3);
		std::cout << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(5);
		std::cout << obj.size() << std::endl;
		print_container_access_operator(obj, obj.size());
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.resize(8);
		std::cout << obj.size() << std::endl;
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
		try {
			src.at(5) = 6;
			std::cout << "Did not throw" << std::endl;
		} catch (std::exception &error) {
			std::cout << " >> Did throw" << std::endl;
		}
	}
	std::cout << "front()" << std::endl;
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " >> " << obj.front() << std::endl;
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.front() = 6;
		std::cout << " >> " << obj.front() << std::endl;
	}
	std::cout << "back()" << std::endl;
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		std::cout << " >> " << obj.back() << std::endl;
	}
	{
		const int arr[5] = {1, 2, 3, 4, 5};
		NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
		obj.back() = 6;
		std::cout << " >> " << obj.back() << std::endl;
	}
}
int	main(void)
{
	integral_contant_testing();
	is_integral_testing();
	vector_testing();
	return 0;
}
