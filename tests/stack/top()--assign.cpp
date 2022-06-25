/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top()--assign.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/23 12:02:48 by vfurmane         ###   ########.fr       */
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
	int										src_arr[] = {1, 2, 3, 4, 5};
	NAMESPACE::stack<int>::container_type	src(src_arr, src_arr + (sizeof src_arr / sizeof *src_arr));
	NAMESPACE::stack<int>					obj(src);
	std::cout << "top(): " << obj.top() << std::endl;
	obj.top() = 7;
	std::cout << "top(): " << obj.top() << std::endl;
}
