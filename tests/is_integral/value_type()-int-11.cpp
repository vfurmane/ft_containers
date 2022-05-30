/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type()-int-11.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:20:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/30 15:09:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "type_traits.hpp"

int	main(void)
{
	std::cout << "value_type() <int> : ";
	NAMESPACE::is_integral<int> obj;
	std::cout << static_cast<bool>(obj) << std::endl;
}
