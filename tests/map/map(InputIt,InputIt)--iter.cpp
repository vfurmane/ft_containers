/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map(InputIt,InputIt)--iter.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 15:04:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

typedef NAMESPACE::map<int, float>::iterator iterator;

int	main(void)
{
	NAMESPACE::pair<const int, float>	src[] = 
	{
		NAMESPACE::pair<const int, float>(40, 3.1415f),
		NAMESPACE::pair<const int, float>(41, 3.1415f),
		NAMESPACE::pair<const int, float>(42, 3.1415f),
		NAMESPACE::pair<const int, float>(43, 3.1415f),
		NAMESPACE::pair<const int, float>(44, 3.1415f)
	};
	NAMESPACE::map<int, float>	obj(src, src + (sizeof src / sizeof *src));
	for (iterator it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
