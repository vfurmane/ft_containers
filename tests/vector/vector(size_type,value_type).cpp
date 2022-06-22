/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector(size_type,value_type).cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 15:52:20 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::vector<int> obj(5, 0);
	(void)obj;
	std::cout << "(size_type," << std::endl;
	std::cout << " const value_type&) : OK" << std::endl;
}
