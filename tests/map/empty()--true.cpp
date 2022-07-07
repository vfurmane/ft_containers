/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty()--true.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:18:07 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/07 12:14:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif
#include "tests/print.hpp"

int	main(void)
{
	NAMESPACE::map<int, float>	obj;
	if (obj.empty())
		return 0;
	return 1;
}
