/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type-int-42-11.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:02:03 by vfurmane          #+#    #+#             */
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
	std::cout << "type <int, 42> : ";
	if (typeid(NAMESPACE::integral_constant<int, 42>::type) == typeid(NAMESPACE::integral_constant<int, 42>))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
