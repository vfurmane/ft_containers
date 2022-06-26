/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_compare.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/26 17:54:23 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	if (typeid(NAMESPACE::map< int, float, TestHelper<COMPARE> >::key_compare) == typeid(TestHelper<COMPARE>))
		return 0;
	else
		return 1;
}
