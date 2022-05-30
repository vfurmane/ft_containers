/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_type-11.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:20:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 11:56:30 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "true_type : ";
	if (typeid(NAMESPACE::integral_constant<bool, true>) == typeid(NAMESPACE::true_type))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
