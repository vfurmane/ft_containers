/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_type-RAIT-int-float.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:06:34 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:08:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <typeinfo>
#ifndef USE_STD
# include "iterator.hpp"
#endif

int	main(void)
{
	std::cout << "difference_type (set to float) : ";
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, float>::difference_type) == typeid(float))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
