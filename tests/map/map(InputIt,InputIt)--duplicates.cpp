/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map(InputIt,InputIt)--duplicates.cpp               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 14:55:54 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestAllocator.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<const int, float>	src[] = 
	{
		NAMESPACE::pair<const int, float>(41, 3.1415f),
		NAMESPACE::pair<const int, float>(42, 3.1415f),
		NAMESPACE::pair<const int, float>(42, 3.1415f),
		NAMESPACE::pair<const int, float>(43, 3.1415f),
		NAMESPACE::pair<const int, float>(44, 3.1415f)
	};
	TestHelper<COMPARE>	comp;
	TestAllocator< NAMESPACE::pair<const int, float> >	allocator;
	NAMESPACE::map< int, float, TestHelper<COMPARE>, TestAllocator< NAMESPACE::pair<const int, float> > >	obj(src, src + (sizeof src / sizeof *src), comp, allocator);
	std::cout << "size() : " << obj.size() << std::endl;
}
