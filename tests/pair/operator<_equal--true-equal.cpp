/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<_equal--true-equal.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 21:52:27 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <utility>
#else
# include "utility.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<int, float>	obj1(42, 3.1415f);
	NAMESPACE::pair<int, float>	obj2(obj1);
	if (obj1 <= obj2)
		return 0;
	else
		return 1;
}
