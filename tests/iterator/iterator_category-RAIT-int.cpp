/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_category-RAIT-int.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:11:34 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:11:54 by vfurmane         ###   ########.fr       */
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
	std::cout << "iterator_category : ";
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::iterator_category) == typeid(NAMESPACE::random_access_iterator_tag))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
