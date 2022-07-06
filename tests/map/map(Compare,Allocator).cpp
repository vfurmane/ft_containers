/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map(Compare,Allocator).cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 16:01:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/TestAllocator.hpp"
#include "tests/TestHelper.hpp"
#include <utility>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	TestHelper<COMPARE>	comp;
	TestAllocator< NAMESPACE::pair<const int, float> >	allocator;
	NAMESPACE::map< int, float, TestHelper<COMPARE>, TestAllocator< NAMESPACE::pair<const int, float> > >	obj(comp, allocator);
}
