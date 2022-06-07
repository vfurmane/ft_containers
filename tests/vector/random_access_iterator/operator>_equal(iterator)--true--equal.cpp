/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator>_equal(iterator)--true--equal.cp          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 14:26:11 by vfurmane         ###   ########.fr       */
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
	int	nbr[] = {42, 21};
	NAMESPACE::vector<int>::iterator	obj(nbr);
	NAMESPACE::vector<int>::iterator	obj1(nbr);
	if (obj >= obj1)
		return 0;
	else
		return 1;
}
