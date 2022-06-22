/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_equal--false.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:23:18 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 09:57:20 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <iterator>
#else
# include "iterator.hpp"
#endif

int	main(void)
{
	std::cout << "x == y operator (false) : ";
	int	nbr[] = {42, 21, 1337, 125};
	int	*src = &nbr[3];
	NAMESPACE::reverse_iterator<int *>	obj1(src - 1);
	NAMESPACE::reverse_iterator<int *>	obj2(src);
	if (obj1 == obj2)
		std::cout << "KO" << std::endl;
	else
		std::cout << "OK" << std::endl;
}
