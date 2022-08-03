/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(Key)--string.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 11:30:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "tests/print.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

typedef NAMESPACE::pair<const std::string, float> pair;
typedef NAMESPACE::map<std::string, float>::iterator iterator;
typedef NAMESPACE::map<int, float>::size_type size_type;

int	main(void)
{
	pair	arr[] = 
	{
		pair("a", 3.1415f),
		pair("b", 3.1415f),
		pair("c", 3.1415f),
		pair("d", 3.1415f),
		pair("e", 3.1415f)
	};
	NAMESPACE::map<std::string, float>	obj(arr, arr + (sizeof arr / sizeof *arr));
	size_type	ret = obj.erase("b");
	std::cout << "size() : " << obj.size() << std::endl;
	std::cout << "ret    : " << ret << std::endl;
	for (iterator it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
