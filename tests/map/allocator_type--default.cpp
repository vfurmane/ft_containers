/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_type--default.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/05 13:04:59 by vfurmane         ###   ########.fr       */
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
	if (typeid(NAMESPACE::map<int, float>::allocator_type) == typeid(std::allocator< NAMESPACE::pair<const int, float> >))
		return 0;
	else
		return 1;
}
