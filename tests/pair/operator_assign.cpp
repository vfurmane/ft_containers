/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_equal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 19:38:58 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::pair<int, float>	src(42, 3.1415);
	NAMESPACE::pair<int, float>	obj;
	obj = src;
	std::cout << "(" << obj.first << ", " << obj.second << ")" << std::endl;
}
