/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:30:03 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 17:32:55 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::vector<int>	obj(5);
	int arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> src(arr, arr + (sizeof (arr) / sizeof (*arr)));
	obj.insert(obj.begin() + 2, src.begin(), src.begin() + 2);
	std::cout << "capacity : " << obj.capacity() << std::endl;
	std::cout << "size     : " << obj.size() << std::endl;
	print_container_iter(obj.begin(), obj.end());
}
