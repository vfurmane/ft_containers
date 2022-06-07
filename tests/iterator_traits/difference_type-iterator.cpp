/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_type-iterator.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:18:08 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:18:25 by vfurmane         ###   ########.fr       */
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
	std::cout << "difference_type : ";
	if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, float> >::difference_type) == typeid(float))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
