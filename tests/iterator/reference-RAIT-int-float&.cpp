/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference-RAIT-int-float&.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:10:41 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:11:02 by vfurmane         ###   ########.fr       */
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
	std::cout << "reference (set to float &) : ";
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, std::ptrdiff_t, int *, float &>::reference) == typeid(float &))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
