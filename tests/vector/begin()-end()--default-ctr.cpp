/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin()-end()--default-ctr.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 11:05:30 by vfurmane         ###   ########.fr       */
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
	const int src[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
	print_container_iter(obj.begin(), obj.end());
}
