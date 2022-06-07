/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign(InputIterator,InputIterator)--size          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 10:49:32 by vfurmane         ###   ########.fr       */
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
	const int src[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
	const int arr[6] = {6, 5, 4, 3, 2, 1};
	obj.assign(arr, arr + (sizeof (arr) / sizeof (*arr)));
	print_container_iter(obj.begin(), obj.end());
}
