/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_argument_type.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:12:53 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/05 14:09:23 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	if (typeid(NAMESPACE::map<int, float>::value_compare::second_argument_type) == typeid(NAMESPACE::pair<const int, float>))
		return 0;
	return 1;
}
