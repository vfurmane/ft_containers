/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin()-end().cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/07 13:46:18 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<const int, float>	arr[] = 
	{
		NAMESPACE::pair<const int, float>(0, 3.1415f),
		NAMESPACE::pair<const int, float>(1, 3.1415f),
		NAMESPACE::pair<const int, float>(2, 3.1415f),
		NAMESPACE::pair<const int, float>(3, 3.1415f),
		NAMESPACE::pair<const int, float>(4, 3.1415f)
	};
	NAMESPACE::map<int, float>	obj(arr, arr + (sizeof arr / sizeof *arr));
	for (NAMESPACE::map<int, float>::iterator it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
