/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const__iterator(iterator).cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/13 11:09:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef USE_STD
# include <vector>
#else
# include "vector.hpp"
#endif

int	main(void)
{
	NAMESPACE::vector<int>::iterator	src;
	NAMESPACE::vector<int>::const_iterator	obj(src);
	(void)obj;
}
