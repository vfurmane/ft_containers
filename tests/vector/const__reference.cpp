/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const__reference.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 15:34:38 by vfurmane         ###   ########.fr       */
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
	std::cout << "const_reference : ";
	if (typeid(NAMESPACE::vector< TestHelper<> >::const_reference) == typeid(const TestHelper<> &))
		std::cout << "OK" << std::endl;
	else
		std::cout << "KO" << std::endl;
}
