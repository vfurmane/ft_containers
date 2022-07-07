/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(iterator,value_type)--bad_hint.cpp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:01:57 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 21:54:01 by vfurmane         ###   ########.fr       */
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
		pair(4, 3.1415f),
		pair(5, 3.1415f)
	};
	NAMESPACE::map<int, float>	obj(arr, arr + (sizeof arr / sizeof *arr));
	iterator ret = obj.insert(obj.begin(), NAMESPACE::make_pair(3, 3.1415f));
	std::cout << "size()  : " << obj.size() << std::endl;
	std::cout << "[3]     : " << obj[3] << std::endl;
	std::cout << "ret     : " << *ret << std::endl;
	std::cout << "begin() : " << *obj.begin() << std::endl;
}
