/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair(T1,T2)--TestHelper.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 19:23:18 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <utility>
#else
# include "utility.hpp"
#endif

int	main(void)
{
	std::pair< int, TestHelper<> >	obj(42, TestHelper<>());
	std::cout << "(" << obj.first << ", " << obj.second << ")" << std::endl;
}
