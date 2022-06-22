/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size()--iter-ctr.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 11:03:18 by vfurmane         ###   ########.fr       */
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
	const int src[7] = {1, 2, 3, 4, 5, 6, 7};
	NAMESPACE::vector<int> obj(src, src + (sizeof (src) / sizeof (*src)));
	std::cout << "with int[7] : " << obj.size() << std::endl;
}
