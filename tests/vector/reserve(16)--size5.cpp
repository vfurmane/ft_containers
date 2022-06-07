/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve(16)--size5.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 13:46:53 by vfurmane         ###   ########.fr       */
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
	obj.reserve(16);
	std::cout << "capacity : " << obj.capacity() << std::endl;
	std::cout << "size     : " << obj.size() << std::endl;
}
