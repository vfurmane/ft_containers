/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator-_assign(difference_type).cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:23:18 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 09:44:46 by vfurmane         ###   ########.fr       */
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
	std::cout << "x -= n operator : ";
	int	nbr[] = {42, 21, 1337};
	int	*src = &nbr[1];
	NAMESPACE::reverse_iterator<int *>	obj(src);
	std::cout << *(obj -= 1) << " - ";
	std::cout << *obj << std::endl;
}
