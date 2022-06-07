/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<_equal--with-copy.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:23:18 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 11:55:09 by vfurmane         ###   ########.fr       */
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
	std::cout << "x <= y operator (with copy) : ";
	int	nbr[] = {42, 21, 1337, 125};
	int	*src = &nbr[3];
	NAMESPACE::reverse_iterator<int *>	obj1(src);
	NAMESPACE::reverse_iterator<int *>	obj2(obj1);
	obj1--;
	if (obj1 <= obj2)
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
