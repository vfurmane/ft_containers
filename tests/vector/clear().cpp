/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear().cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:24:20 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 12:13:44 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::vector<int>	obj(5);
	obj.clear();
	std::cout << "size     : " << obj.size() << std::endl;
	std::cout << "capacity : " << obj.capacity() << std::endl;
}
