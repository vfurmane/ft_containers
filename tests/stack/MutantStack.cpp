/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 14:39:28 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include <vector>
#include "tests/MutantStack.hpp"
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

typedef MutantStack< int, NAMESPACE::vector<int> >::const_iterator MSC_iterator;

int	main(void)
{
	int	arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector<int>	src(arr, arr + (sizeof arr / sizeof *arr));
	MutantStack< int, NAMESPACE::vector<int> >	obj(src);
	for	(MSC_iterator it = obj.begin(); it != obj.end(); ++it)
	{
		std::cout << *it << std::endl;
	};
}
