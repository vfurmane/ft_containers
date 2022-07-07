/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_assign()--iter.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/06 20:49:39 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<const int, float>	arr[] = 
	{
		NAMESPACE::pair<const int, float>(40, 3.1415f),
		NAMESPACE::pair<const int, float>(41, 3.1415f),
		NAMESPACE::pair<const int, float>(42, 3.1415f),
		NAMESPACE::pair<const int, float>(43, 3.1415f),
		NAMESPACE::pair<const int, float>(44, 3.1415f)
	};
	NAMESPACE::map<int, float>	src(arr, arr + (sizeof arr / sizeof *arr));
	NAMESPACE::map<int, float>	obj = src;
}

