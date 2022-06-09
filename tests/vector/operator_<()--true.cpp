/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_<()--true.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:15:46 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 14:07:10 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::vector<int>	obj1(5);
	NAMESPACE::vector<int>	obj2(5);
	obj2[3] = 7;
	if (obj1 < obj2)
		return 0;
	else
		return 1;
}
