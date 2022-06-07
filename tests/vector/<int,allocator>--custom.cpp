/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   <int,allocator>--custom.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/04 15:38:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestAllocator.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector< int, TestAllocator<int> > obj(2);
	return 0;
}
