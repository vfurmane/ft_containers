/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_type.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/26 18:41:47 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "tests/TestAllocator.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	if (typeid(NAMESPACE::map< int, float, std::less<int>, TestAllocator< NAMESPACE::pair<const int, float> > >::allocator_type) == typeid(TestAllocator< NAMESPACE::pair<const int, float> >))
		return 0;
	else
		return 1;
}
