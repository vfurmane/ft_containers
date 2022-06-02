/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false_type-11.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:20:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 11:54:04 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#ifndef USE_STD
# include "type_traits.hpp"
#endif

int	main(void)
{
	std::cout << "false_type : ";
	if (typeid(NAMESPACE::integral_constant<bool, false>) == typeid(NAMESPACE::false_type))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
