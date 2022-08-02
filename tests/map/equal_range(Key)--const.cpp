/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range(Key)--const.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 14:13:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include "tests/print.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

typedef NAMESPACE::pair<const int, float> pair;
typedef NAMESPACE::map<int, float>::const_iterator const_iterator;

int	main(void)
{
	pair	arr[] = 
	{
		pair(1, 3.1415f),
		pair(2, 3.1415f),
		pair(3, 3.1415f),
		pair(4, 3.1415f),
		pair(5, 3.1415f)
	};
	NAMESPACE::map<int, float>	obj(arr, arr + (sizeof arr / sizeof *arr));
	NAMESPACE::pair<const_iterator, const_iterator>	ret = (static_cast< const NAMESPACE::map<int, float> * >(&obj))->equal_range(3);
	for (const_iterator it = ret.first; it != ret.second; ++it)
		std::cout << *it << std::endl;
	std::cout << "first == second ? " << (ret.first == ret.second) << std::endl;
}
