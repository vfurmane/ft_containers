/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push().cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/24 16:41:10 by vfurmane         ###   ########.fr       */
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
	int										arr[] = {1, 2, 3, 4, 5};
	NAMESPACE::stack<int>::container_type	src(arr, arr + (sizeof arr / sizeof *arr));
	NAMESPACE::stack<int>					obj(src);
	obj.push(6);
	std::cout << "size : " << obj.size() << std::endl;
	std::cout << "top  : " << obj.top() << std::endl;
}
