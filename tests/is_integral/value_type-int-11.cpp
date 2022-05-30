/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type-int-11.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:20:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:17:19 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "value_type == bool : ";
	if (typeid(NAMESPACE::is_integral<int>::value_type) == typeid(bool))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
