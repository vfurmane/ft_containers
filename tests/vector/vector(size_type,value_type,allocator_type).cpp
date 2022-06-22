/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector(size_type,value_type,allocator_typ          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 15:54:24 by vfurmane         ###   ########.fr       */
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
	std::allocator<int> alloc;
	NAMESPACE::vector<int> obj(5, 0, alloc);
	(void)obj;
	std::cout << "(size_type," << std::endl;
	std::cout << " const value_type&," << std::endl;
	std::cout << " const allocator_type&) : OK" << std::endl;
}
