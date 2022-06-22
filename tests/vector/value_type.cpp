/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 15:32:12 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	std::cout << "value_type : ";
	if (typeid(NAMESPACE::vector< TestHelper<> >::value_type) == typeid(TestHelper<>))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
