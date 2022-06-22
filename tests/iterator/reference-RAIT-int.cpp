/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference-RAIT-int.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:09:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:10:13 by vfurmane         ###   ########.fr       */
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
	std::cout << "reference : ";
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int>::reference) == typeid(int &))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
