/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair(pair<U1,U2>).cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 22:25:01 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::pair<char, bool>	src('v', true);
	NAMESPACE::pair<int, float>	obj(src);
	std::cout << "(" << obj.first << ", " << obj.second << ")" << std::endl;
}
