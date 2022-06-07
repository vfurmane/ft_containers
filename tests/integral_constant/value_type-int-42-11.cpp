/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type-int-42-11.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:45:33 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 11:58:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#ifndef USE_STD
# include "type_traits.hpp"
#endif

int	main(void)
{
	std::cout << "value_type <int, 42> == int : ";
	if (typeid(NAMESPACE::integral_constant<int, 42>::value_type) == typeid(int))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
