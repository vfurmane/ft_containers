/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty()--TestHelper.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:36:54 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/24 14:39:21 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

int	main(void)
{
	NAMESPACE::stack< int, TestHelper<STACK> >	obj;
	std::cout << "is ";
	if (!obj.empty())
		std::cout << "not ";
	std::cout << "empty" << std::endl;
}
