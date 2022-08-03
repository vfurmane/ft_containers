/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count()--1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 11:44:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

typedef NAMESPACE::pair<const int, float> pair;

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
	if (obj.count(3))
		return 0;
	return 1;
}
