/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator<_equal(iterator)--false--greater          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/07 12:29:25 by vfurmane         ###   ########.fr       */
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
	NAMESPACE::vector<int>::iterator	obj1(&nbr[1]);
	if (obj1 <= obj)
		return 1;
	else
		return 0;
}
