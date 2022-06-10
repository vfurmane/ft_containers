/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator(const__reverse_iterator&          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:34:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 15:12:20 by vfurmane         ###   ########.fr       */
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
	int	*src = NULL;
	NAMESPACE::reverse_iterator<int *>	obj(src);
	std::cout << "(const reverse_iterator<Iter> &) : OK" << std::endl;
}
