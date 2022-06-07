/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector(InputIterator,InputIterator)--iter          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 10:59:25 by vfurmane         ###   ########.fr       */
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
	std::cout << "(InputIterator," << std::endl;
	std::cout << " InputIterator) <int *> : OK" << std::endl;
	print_container_iter(obj.begin(), obj.end());
}
