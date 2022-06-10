/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_type-RAIT-int.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:05:43 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:06:04 by vfurmane         ###   ########.fr       */
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
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::difference_type) == typeid(std::ptrdiff_t))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
