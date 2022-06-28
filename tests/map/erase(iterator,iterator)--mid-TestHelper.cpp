/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(iterator,iterator)--mid-TestHelper.cpp       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 11:14:59 by vfurmane         ###   ########.fr       */
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
	obj.erase(++obj.begin(), --obj.end());
	std::cout << "size()  : " << obj.size() << std::endl;
	for (iterator it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
