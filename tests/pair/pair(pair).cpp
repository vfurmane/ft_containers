/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair(pair).cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 19:20:25 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifdef USE_STD
# include <utility>
#else
# include "utility.hpp"
#endif

int	main(void)
{
	std::pair<int, float>	src(42, 3.1415f);
	std::pair<int, float>	obj(src);
	std::cout << "(" << obj.first << ", " << obj.second << ")" << std::endl;
}
