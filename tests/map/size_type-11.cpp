/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_type-11.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/05 11:29:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "tests/custom_type_traits.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	if (!is_integral<NAMESPACE::map<int, float>::size_type>())
		return 1;
	if (is_signed<NAMESPACE::map<int, float>::size_type>())
		return 1;
	return 0;
}
