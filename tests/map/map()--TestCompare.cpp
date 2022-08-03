/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map()--TestCompare.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/05 16:08:45 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	NAMESPACE::map< int, float, TestHelper<COMPARE> >	obj;
}
