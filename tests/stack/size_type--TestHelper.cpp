/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_type--TestHelper.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/23 11:43:23 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

int	main(void)
{
	if (typeid(NAMESPACE::stack< int, TestHelper<STACK> >::size_type) == typeid(TestHelper<STACK>::size_type))
		return 0;
	else
		return 1;
}
