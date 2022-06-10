/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_type-const-T*.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:19:47 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:20:17 by vfurmane         ###   ########.fr       */
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
	std::cout << "difference_type (const T *) : ";
	if (typeid(NAMESPACE::iterator_traits<const int *>::difference_type) == typeid(std::ptrdiff_t))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
