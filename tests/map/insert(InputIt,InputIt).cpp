/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(InputIt,InputIt).cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:01:57 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 22:09:33 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::map<int, float>	obj;
	obj.insert(arr, arr + (sizeof arr / sizeof *arr));
	std::cout << "size()  : " << obj.size() << std::endl;
	for (iterator it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
