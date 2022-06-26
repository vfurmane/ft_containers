/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_type-11.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/26 17:30:58 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <type_traits>
#include <typeinfo>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	if (!std::is_integral<NAMESPACE::map<int, float>::difference_type>())
		return 1;
	if (!std::is_signed<NAMESPACE::map<int, float>::difference_type>())
		return 1;
	return 0;
}
