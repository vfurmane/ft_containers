/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<--true-lower-first-greater-second.cp      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:14:55 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/26 12:15:16 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <utility>
#else
# include "utility.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<int, float>	obj1(21, 3.1415f);
	NAMESPACE::pair<int, float>	obj2(42, 2.7182);
	if (obj1 < obj2)
		return 0;
	else
		return 1;
}
