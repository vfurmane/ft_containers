/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference--TestHelper.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/23 11:45:58 by vfurmane         ###   ########.fr       */
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
	if (typeid(NAMESPACE::stack< float, TestHelper<STACK, float> >::reference) == typeid(float &))
		return 0;
	else
		return 1;
}
