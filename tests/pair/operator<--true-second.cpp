/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<--true-second.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 20:17:23 by vfurmane         ###   ########.fr       */
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
	std::pair<int, float>	obj1(42, 2.7182f);
	std::pair<int, float>	obj2(42, 3.1415f);
	if (obj1 < obj2)
		return 0;
	else
		return 1;
}
