/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value-bool-true-11.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:15:44 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:16:32 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "value <bool, true> : ";
	std::cout << NAMESPACE::integral_constant<bool, true>::value << std::endl;
}
