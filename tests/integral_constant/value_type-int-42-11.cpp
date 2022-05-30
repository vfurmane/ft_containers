/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type-int-42-11.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:45:33 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:17:07 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "value_type <int, 42> == int : ";
	if (typeid(NAMESPACE::integral_constant<int, 42>::value_type) == typeid(int))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
