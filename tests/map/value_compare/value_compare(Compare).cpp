/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_compare(Compare).cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:12:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 12:54:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/TestCompare.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	TestHelper<COMPARE>	src;
	TestCompare< int, float, TestHelper<COMPARE> >	obj(src);
	(void)obj;
}
