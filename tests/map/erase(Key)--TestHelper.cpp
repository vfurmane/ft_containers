/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(Key)--TestHelper.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 11:29:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

typedef NAMESPACE::pair< const int, TestHelper<> > pair;
typedef NAMESPACE::map< int, TestHelper<> >::iterator iterator;
typedef NAMESPACE::map<int, float>::size_type size_type;

int	main(void)
{
	pair	arr[] = 
	{
		pair(0, 42),
		pair(1, 42),
		pair(2, 42),
		pair(3, 42),
		pair(4, 42)
	};
	NAMESPACE::map< int, TestHelper<> >	obj(arr, arr + (sizeof arr / sizeof *arr));
	size_type	ret = obj.erase(3);
	std::cout << "size() : " << obj.size() << std::endl;
	std::cout << "ret    : " << ret << std::endl;
	for (iterator it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
