/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<_equal--false-first.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 21:51:11 by vfurmane         ###   ########.fr       */
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
	std::pair<int, float>	obj1(1337, 3.1415f);
	std::pair<int, float>	obj2(42, 3.1415f);
	if (obj1 <= obj2)
		return 1;
	else
		return 0;
}