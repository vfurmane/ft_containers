/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 16:44:41 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <typeinfo>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::map<int, float>	obj;
	if (typeid(obj.get_allocator()) == typeid(std::allocator< NAMESPACE::pair<const int, float> >))
		return 0;
	return 1;
}
