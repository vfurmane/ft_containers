/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type()-bool-true-11.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:56:19 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:57:14 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "value_type() <bool, true> : ";
	NAMESPACE::integral_constant<bool, true> obj;
	std::cout << static_cast<bool>(obj) << std::endl;
}
