/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base(void).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:34:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 15:07:47 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <iterator>
#else
# include "iterator.hpp"
#endif

int	main(void)
{
	std::cout << "base()" << std::endl;
	int	*src = NULL;
	NAMESPACE::reverse_iterator<int	*>	obj(src);
	std::cout << "src is ";
	if (src != obj.base())
		std::cout << "not ";
	std::cout << "equal to obj.base()" << std::endl;
}
