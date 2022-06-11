/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at().cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 21:27:38 by vfurmane         ###   ########.fr       */
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
	std::cout << " at(4) >> ";
	try {
		(void)src.at(4);
		std::cout << "Did not throw" << std::endl;
	} catch (std::exception &error) {
		std::cout << "Did throw" << std::endl;
	}
}
