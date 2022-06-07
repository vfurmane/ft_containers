/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator+(int,iterator).cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 12:07:20 by vfurmane         ###   ########.fr       */
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
	int	nbr[] = {42, 21};
	NAMESPACE::vector<int>::iterator	obj(nbr);
	std::cout << *(1 + obj) << " | ";
	std::cout << *obj << std::endl;
}
