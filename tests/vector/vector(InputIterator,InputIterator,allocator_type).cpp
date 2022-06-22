/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector(InputIterator,InputIterator,alloca          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 16:00:08 by vfurmane         ###   ########.fr       */
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
	int arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> obj(arr, arr + (sizeof (arr) / sizeof (*arr)), alloc);
	std::cout << " (InputIterator," << std::endl;
	std::cout << "  InputIterator," << std::endl;
	std::cout << "  const allocator_type&) <int *> : OK" << std::endl;
}
