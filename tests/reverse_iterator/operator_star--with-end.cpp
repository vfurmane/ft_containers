/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator*--with-end.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:17:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 16:45:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <iterator>
# include <vector>
#else
# include "iterator.hpp"
# include "vector.hpp"
#endif

int	main(void)
{
	std::cout << "*x operator (with end()) : ";
	int	nbr[] = {42, 21, 1337};
	NAMESPACE::vector<int> src(&nbr[0], &nbr[2]);
	NAMESPACE::vector<int>::reverse_iterator	obj(src.end());
	std::cout << *obj << std::endl;
}
