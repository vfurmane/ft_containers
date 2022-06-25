/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_type--TestHelper.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/23 11:40:40 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

int	main(void)
{
	if (typeid(NAMESPACE::stack< TestHelper<> >::value_type) == typeid(TestHelper<>))
		return 0;
	else
		return 1;
}
