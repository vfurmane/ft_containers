/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_equal(vector)--deep-copy.cpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 15:27:55 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <tests/TestHelper.hpp>
#include <tests/print.hpp>
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector<TestHelper> src(5);
	NAMESPACE::vector<TestHelper> copy(3);
	copy = src;
	std::cout << copy.size() << std::endl;
	src[2].nbr = 1336;
	copy[2].nbr = 21;
	print_container_iter(src.begin(), src.end());
	print_container_iter(copy.begin(), copy.end());
}
