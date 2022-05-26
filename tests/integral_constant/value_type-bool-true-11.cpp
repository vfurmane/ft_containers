/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type-bool-true-11.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:16:25 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/26 15:34:18 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << " value_type <bool, true> == bool" << std::endl;
	if (typeid(NAMESPACE::integral_constant<bool, true>::value_type) == typeid(bool))
		return 0;
	else
		return 1;
}
