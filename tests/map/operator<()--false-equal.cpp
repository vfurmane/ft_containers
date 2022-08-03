/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<()--false-equal.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 19:09:26 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/TestAllocator.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<const int, float>	arr[] = 
	{
		NAMESPACE::pair<const int, float>(0, 3.1415f),
		NAMESPACE::pair<const int, float>(1, 3.1415f)
	};
	NAMESPACE::map<int, float>	obj1(arr, arr + (sizeof arr / sizeof *arr));
	NAMESPACE::map<int, float>	obj2(obj1);
	if (obj1 < obj2)
		return 1;
	return 0;
}
