/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign(4,float).cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:36:42 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/20 15:37:06 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/print.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector<float> obj(5);
	obj.assign(4, 2.0f);
	print_container_iter(obj.begin(), obj.end());
}
