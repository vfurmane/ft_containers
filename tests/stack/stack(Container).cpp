/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack(Container).cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:04 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/22 21:00:36 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#ifdef USE_STD
# include <stack>
#else
# include "stack.hpp"
#endif

int	main(void)
{
	std::vector<int>							src;
	NAMESPACE::stack< int, std::vector<int> >	obj(src);
	(void)src;
}
