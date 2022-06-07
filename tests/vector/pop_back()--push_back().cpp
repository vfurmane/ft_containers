/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_back()--push_back().cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 11:02:30 by vfurmane         ###   ########.fr       */
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
	obj.push_back(42);
	obj.pop_back();
	std::cout << "size     : " << obj.size() << std::endl;
	std::cout << "capacity : " << obj.capacity() << std::endl;
	std::cout << "back     : " << obj.back() << std::endl;
}
