/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator-.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:23:18 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 14:12:16 by vfurmane         ###   ########.fr       */
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
	std::cout << " x - y operator : ";
	int	nbr[] = {42, 21, 1337};
	int	*src1 = &nbr[0];
	int	*src2 = &nbr[1];
	int	*src3 = &nbr[2];
	NAMESPACE::reverse_iterator<int *>	obj1(src1);
	NAMESPACE::reverse_iterator<int *>	obj2(src2);
	NAMESPACE::reverse_iterator<int *>	obj3(src3);
	std::cout << obj1 - obj3 << " | ";
	std::cout << obj1 - obj2 << " | ";
	std::cout << obj1 - obj1 << " | ";
	std::cout << obj2 - obj1 << " | ";
	std::cout << obj3 - obj1 << std::endl;
}
