/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty()--false.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 13:44:21 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::vector<int> obj(5);
	std::cout << "is ";
	if (obj.empty())
		std::cout << "empty" << std::endl;
	else
		std::cout << "not empty" << std::endl;
}
