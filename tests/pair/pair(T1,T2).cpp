/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair(T1,T2)--print.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 19:18:33 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::pair<int, float>	obj(42, 3.1415f);
	std::cout << "(" << obj.first << ", " << obj.second << ")" << std::endl;
}
