/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbegin()-rend().cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 11:01:00 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/print.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> src(arr, arr + (sizeof (arr) / sizeof (*arr)));
	print_container_iter(src.rbegin(), src.rend());
}
