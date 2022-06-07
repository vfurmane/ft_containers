/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator->.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:23:18 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 09:46:42 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <iterator>
#else
# include "iterator.hpp"
#endif

int	main(void)
{
	std::cout << "x->n operator : ";
	TestHelper	test_helper;
	TestHelper	*src = &test_helper;
	NAMESPACE::reverse_iterator<TestHelper *>	obj(src);
	obj->greet();
}
