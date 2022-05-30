/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type()-bool-false-11.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:56:19 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:57:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "value <bool, false> : ";
	std::cout << NAMESPACE::integral_constant<bool, false>::value << std::endl;
}
