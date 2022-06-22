/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer-RAIT-int-float*.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:09:13 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 14:09:32 by vfurmane         ###   ########.fr       */
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
	std::cout << "pointer (set to float *) : ";
	if (typeid(NAMESPACE::iterator<NAMESPACE::random_access_iterator_tag, int, std::ptrdiff_t, float *>::pointer) == typeid(float *))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
