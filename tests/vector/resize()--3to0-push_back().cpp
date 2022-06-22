/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize()--3to0-push_back().cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 11:14:07 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector< TestHelper<> > obj(3);
	obj.resize(0);
	obj.push_back(TestHelper<>());
	std::cout << "size : " << obj.size() << std::endl;
	print_container_iter(obj.begin(), obj.end());
}
