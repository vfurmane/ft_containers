/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator().cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:12:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 14:51:10 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	NAMESPACE::pair<const int, float>	pair1(21, 3.1415f);
	NAMESPACE::pair<const int, float>	pair2(42, 3.1415f);
	std::cout << "pair1 < pair2 ? " << obj(pair1, pair2) << std::endl;
}
