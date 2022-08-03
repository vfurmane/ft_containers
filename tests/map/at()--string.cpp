/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at()--string.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 19:48:32 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <string>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<const std::string, int>	arr[] = 
	{
		NAMESPACE::pair<const std::string, int>("a", 42),
		NAMESPACE::pair<const std::string, int>("b", 42),
		NAMESPACE::pair<const std::string, int>("c", 42),
		NAMESPACE::pair<const std::string, int>("d", 42),
		NAMESPACE::pair<const std::string, int>("e", 42)
	};
	NAMESPACE::map<std::string, int>	obj(arr, arr + (sizeof arr / sizeof *arr));
	std::cout << "at(\"d\") : " << obj.at("d") << std::endl;
}
