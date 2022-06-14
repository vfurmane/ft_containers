/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:29:47 by vfurmane          #+#    #+#             */
/*   Updated: 2022/03/23 20:27:53 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
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

	// template<bool B, class T = void>
	// struct enable_if
	// {
	// };

	// template<class T>
	// struct enable_if<true, T>
	// {
	// 	typedef T type;
	// };

	template<class T>
	struct remove_const
	{
		typedef T type;
	};
	template<class T>
	struct remove_const<const T>
	{
		typedef T type;
	};
};
