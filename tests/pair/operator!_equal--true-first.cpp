/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator!_equal--true-first.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 20:12:30 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::pair<int, float>	obj1(42, 3.1415);
	NAMESPACE::pair<int, float>	obj2(0, 3.1415);
	if (obj1 != obj2)
		return 0;
	else
		return 1;
}
