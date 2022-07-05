/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:11:10 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/05 11:28:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_TYPE_TRAITS_HPP
# define TESTS_TYPE_TRAITS_HPP

template <class T, T v>
struct integral_constant {
	const static T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator T()
	{
		return v;
	}
};

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;

template <typename T>
struct is_integral : public false_type {};
template <>
struct is_integral<bool> : public true_type {};
template<>
struct is_integral<char> : public true_type {};
template<>
struct is_integral<wchar_t> : public true_type {};
template<>
struct is_integral<signed char> : public true_type {};
template<>
struct is_integral<short int> : public true_type {};
template<>
struct is_integral<int> : public true_type {};
template<>
struct is_integral<long int> : public true_type {};
template<>
struct is_integral<long long int> : public true_type {};
template<>
struct is_integral<unsigned char> : public true_type {};
template<>
struct is_integral<unsigned short int> : public true_type {};
template<>
struct is_integral<unsigned int> : public true_type {};
template<>
struct is_integral<unsigned long int> : public true_type {};
template<>
struct is_integral<unsigned long long int> : public true_type {};

template<typename>
struct is_floating_point : public false_type { };
template<>
struct is_floating_point<float> : public true_type { };
template<>
struct is_floating_point<double> : public true_type { };
template<>
struct is_floating_point<long double> : public true_type { };

template<bool, typename, typename>
struct conditional;

template<typename B1, typename B2>
struct or_ : public conditional<B1::value, B1, B2>::type { };

template<typename T>
struct is_arithmetic : public or_< is_integral<T>, is_floating_point<T> >::type { };

template<typename T>
struct is_signed : public integral_constant<bool, T(-1) < T(0)> { };

#endif
