/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator-(iterator).cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 12:07:46 by vfurmane         ###   ########.fr       */
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
	int	nbr[] = {42, 21, 1337};
	NAMESPACE::vector<int>::iterator	obj(nbr);
	NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
	NAMESPACE::vector<int>::iterator	obj2(&nbr[2]);
	std::cout << obj - obj2 << " | ";
	std::cout << obj - obj1 << " | ";
	std::cout << obj - obj << " | ";
	std::cout << obj1 - obj << " | ";
	std::cout << obj2 - obj << std::endl;
}
