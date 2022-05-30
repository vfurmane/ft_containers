/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type-bool-true-11.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:58:44 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:15:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "type <bool, true> : ";
	if (typeid(NAMESPACE::integral_constant<bool, true>::type) == typeid(NAMESPACE::integral_constant<bool, true>))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
