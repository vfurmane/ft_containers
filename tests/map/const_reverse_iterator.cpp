/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:59:35 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/05 13:06:14 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#ifdef USE_STD
# include <map>
#else
# include "map.hpp"
#endif

int	main(void)
{
	if (typeid(std::iterator_traits<NAMESPACE::map<int, float>::const_reverse_iterator>::iterator_category) != typeid(NAMESPACE::bidirectional_iterator_tag))
		return 1;
	if (typeid(*NAMESPACE::map<int, float>::const_reverse_iterator()) != typeid(const NAMESPACE::pair<const int, float>))
		return 1;
	return 0;
}
