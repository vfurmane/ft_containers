/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_bound(Key)--underflow.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 14:52:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

typedef NAMESPACE::pair<const int, float> pair;
typedef NAMESPACE::map<int, float>::iterator iterator;

int	main(void)
{
	pair	arr[] = 
	{
		pair(0, 3.1415f),
		pair(1, 3.1415f),
		pair(2, 3.1415f),
		pair(3, 3.1415f),
		pair(4, 3.1415f)
	};
	NAMESPACE::map<int, float>	obj(arr, arr + (sizeof arr / sizeof *arr));
	iterator	ret = obj.upper_bound(-3);
	std::cout << *ret << std::endl;
}
