/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type()-int-42-11.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:56:19 by vfurmane          #+#    #+#             */
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
	std::cout << "value <int, 42> : ";
	std::cout << NAMESPACE::integral_constant<int, 42>::value << std::endl;
}
