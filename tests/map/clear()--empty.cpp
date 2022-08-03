/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear()--empty.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:01:57 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 20:05:19 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::map<int, float>	obj;
	obj.clear();
	std::cout << "size() : " << obj.size() << std::endl;
}
