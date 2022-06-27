/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestCompare.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:03:01 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 14:44:52 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_COMPARE_HPP
# define TEST_COMPARE_HPP

# include <iostream>
#include <map>
# include <memory>

template< class Key, class T, class Compare = std::less<Key> >
struct TestCompare : public NAMESPACE::map<Key, T, Compare>::value_compare
{
	typedef NAMESPACE::map<Key, T, Compare>	_Base;

	TestCompare(Compare c) : _Base::value_compare(c), comp(_Base::value_compare::comp)
	{
	}

	bool	operator()(const typename _Base::value_type& lhs, const typename _Base::value_type& rhs) const
	{
		return _Base::value_compare::operator()(lhs, rhs);
	}

	Compare	&comp;
};

#endif
