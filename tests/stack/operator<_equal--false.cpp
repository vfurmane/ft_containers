/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<_equal--false.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 15:10:44 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	std::vector<int>	src(arr, arr + (sizeof arr / sizeof *arr));
	NAMESPACE::stack< int, std::vector<int> >	obj1(src);
	NAMESPACE::stack< int, std::vector<int> >	obj2(src);
	obj2.pop();
	if (obj1 <= obj2)
		return 1;
	else
		return 0;
}
