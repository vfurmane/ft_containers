/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator+(difference_type,reverse_iterato          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:23:18 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 14:08:43 by vfurmane         ###   ########.fr       */
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
	std::cout << "n + x operator : ";
	int	nbr[] = {42, 21, 1337};
	int	*src = &nbr[2];
	NAMESPACE::reverse_iterator<int *>	obj(src);
	std::cout << *(1 + obj) << " - ";
	std::cout << *obj << std::endl;
}
