/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert(Iterator,T)--front.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:08:01 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/08 11:54:54 by vfurmane         ###   ########.fr       */
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
	int arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
	NAMESPACE::vector<int>::iterator pos = obj.insert(obj.begin(), 42);
	std::cout << "position : " << *pos << std::endl;
	std::cout << "size     : " << obj.size() << std::endl;
	std::cout << "capacity : " << obj.capacity() << std::endl;
	std::cout << "[0]      : " << obj.front() << std::endl;
}
