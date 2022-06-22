/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(begin(),0,42)--iter.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:24:31 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/08 11:55:49 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
	obj.insert(obj.begin(), 0, 42);
	std::cout << "size     : " << obj.size() << std::endl;
	std::cout << "capacity : " << obj.capacity() << std::endl;
	print_container_iter(obj.begin(), obj.end());
}
