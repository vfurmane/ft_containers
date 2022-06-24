/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty()--true.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:36:54 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/24 14:38:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

int	main(void)
{
	NAMESPACE::stack<int>	obj;
	std::cout << "is ";
	if (!obj.empty())
		std::cout << "not ";
	std::cout << "empty" << std::endl;
}
