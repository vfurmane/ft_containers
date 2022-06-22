/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at()--overflow.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 21:26:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector<int> src(5, 0);
	std::cout << " at(5) >> ";
	try {
		src.at(5) = 6;
		std::cout << "Did not throw" << std::endl;
	} catch (std::exception &error) {
		std::cout << "Did throw" << std::endl;
	}
}
