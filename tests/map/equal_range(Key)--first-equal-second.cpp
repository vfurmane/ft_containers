/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_range(Key)--first-equal-second.cpp           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:48:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 14:02:08 by vfurmane         ###   ########.fr       */
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

typedef NAMESPACE::pair<const float, int> pair;
typedef NAMESPACE::map<float, int>::iterator iterator;

int	main(void)
{
	pair	arr[] = 
	{
		pair(0.0f, 42),
		pair(1.0f, 42),
		pair(2.0f, 42),
		pair(3.4f, 42),
		pair(4.0f, 42)
	};
	NAMESPACE::map<float, int>	obj(arr, arr + (sizeof arr / sizeof *arr));
	NAMESPACE::pair<iterator, iterator>	ret = obj.equal_range(3);
	for (iterator it = ret.first; it != ret.second; ++it)
		std::cout << *it << std::endl;
	std::cout << "first == second ? " << (ret.first == ret.second) << std::endl;
}
