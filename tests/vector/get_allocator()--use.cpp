/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator()--use.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:15:46 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 13:49:44 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector<int>	obj(5);
	NAMESPACE::vector<int>::allocator_type	alloc = obj.get_allocator();
	int	*ptr;
	ptr = alloc.allocate(1);
	*ptr = 42;
	alloc.deallocate(ptr);
}
