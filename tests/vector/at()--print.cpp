/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at()--print.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 21:22:52 by vfurmane         ###   ########.fr       */
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
	const size_t	size = 5;
	NAMESPACE::vector<int> src(size, 0);
	for (size_t i = 0; i < size; i++)
		std::cout << src.at(i) << (i < size - 1 ? ", " : "");
	std::cout << std::endl;
}
