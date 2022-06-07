/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type-iterator.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:21:41 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:21:56 by vfurmane         ###   ########.fr       */
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
	std::cout << "value_type : ";
	if (typeid(NAMESPACE::iterator_traits< NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int> >::value_type) == typeid(int))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
