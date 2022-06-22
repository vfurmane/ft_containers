/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase(iterator,iterator)--back.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:24:20 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 10:26:28 by vfurmane         ###   ########.fr       */
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
	int	arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int>	obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
	NAMESPACE::vector<int>::iterator pos = obj.erase(obj.end(), obj.end());
	std::cout << "position : " << *pos << std::endl;
	std::cout << "size     : " << obj.size() << std::endl;
	std::cout << "capacity : " << obj.capacity() << std::endl;
	std::cout << "back     : " << obj.back() << std::endl;
}
