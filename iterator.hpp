/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:46:17 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 15:09:22 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"
#include "type_traits.hpp"

namespace ft
{
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
	class iterator
	{
		public:
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};
}

#include "reverse_iterator.hpp"

#endif
