/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(value_type)--exists.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:01:57 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 20:37:12 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::pair<iterator, bool>	ret = obj.insert(NAMESPACE::make_pair(4, 2.7182f));
	std::cout << "size() : " << obj.size() << std::endl;
	std::cout << "[4]    : " << obj[4] << std::endl;
	std::cout << "ret    : ";
	std::cout << "(" << *ret.first << ", " << ret.second << ")" << std::endl;
}
