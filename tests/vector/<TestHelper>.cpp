/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < TestHelper<> >.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:26:50 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/03 14:30:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tests/TestHelper.hpp"
#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

typedef NAMESPACE::vector< TestHelper<> > test_type;

int	main(void)
{
	return 0;
}
