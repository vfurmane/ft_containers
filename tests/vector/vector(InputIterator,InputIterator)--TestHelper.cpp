/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector(InputIterator,InputIterator)--TestHelp      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:53:11 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/23 16:08:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	int arr[5] = {1, 2, 3, 4, 5};
	NAMESPACE::vector< TestHelper<> >	obj(arr, arr + (sizeof (arr) / sizeof (*arr)));
	(void)obj;
}
