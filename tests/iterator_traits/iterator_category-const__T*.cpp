/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_category-const__T*.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:22:36 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:27:29 by vfurmane         ###   ########.fr       */
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
	std::cout << "iterator_category (const T *) : ";
	if (typeid(NAMESPACE::iterator_traits<const int *>::iterator_category) == typeid(NAMESPACE::random_access_iterator_tag))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
