/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap(map).cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 11:38:45 by vfurmane         ###   ########.fr       */
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
typedef NAMESPACE::map<int, float>::size_type size_type;

int	main(void)
{
	pair	arr1[] = 
	{
		pair(1, 3.1415f),
		pair(2, 3.1415f),
		pair(3, 3.1415f),
		pair(4, 3.1415f),
		pair(5, 3.1415f)
	};
	pair	arr2[] = 
	{
		pair(4, 2.7182f),
		pair(5, 2.7182f),
		pair(6, 2.7182f),
		pair(7, 2.7182f),
	};
	NAMESPACE::map<int, float>	obj1(arr1, arr1 + (sizeof arr1 / sizeof *arr1));
	NAMESPACE::map<int, float>	obj2(arr2, arr2 + (sizeof arr2 / sizeof *arr2));
	obj1.swap(obj2);
	std::cout << ">>> obj1" << std::endl;
	std::cout << "size() : " << obj1.size() << std::endl;
	for (iterator it = obj1.begin(); it != obj1.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << ">>> obj2" << std::endl;
	std::cout << "size() : " << obj2.size() << std::endl;
	for (iterator it = obj2.begin(); it != obj2.end(); ++it)
		std::cout << *it << std::endl;
}
