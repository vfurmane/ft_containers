/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap(vector,vector)--bigger--iter.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:24:20 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 15:35:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector<int>	obj1(3, 42);
	NAMESPACE::vector<int>	obj2(19, 21);
	swap(obj1, obj2);
	print_container_iter(obj1.begin(), obj1.end());
	print_container_iter(obj2.begin(), obj2.end());
	std::cout << "size     : " << obj1.size() << " | " << obj2.size() << std::endl;
	std::cout << "capacity : " << obj1.capacity() << " | " << obj2.capacity() << std::endl;
}
