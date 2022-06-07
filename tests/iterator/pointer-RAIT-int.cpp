/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer-RAIT-int.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:07:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:08:24 by vfurmane         ###   ########.fr       */
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
	std::cout << "pointer : ";
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::pointer) == typeid(int *))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
