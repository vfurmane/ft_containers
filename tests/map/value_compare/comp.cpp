/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:12:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 13:11:19 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "tests/TestCompare.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	TestHelper<COMPARE>	src;
	TestCompare< int, float, TestHelper<COMPARE> >	obj(src);
	if (typeid(obj.comp) == typeid(TestHelper<COMPARE>))
		return 0;
	return 1;
}
