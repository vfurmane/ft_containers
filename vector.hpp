/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:05:21 by vfurmane          #+#    #+#             */
/*   Updated: 2022/03/12 11:38:33 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
	class _vector_iterator {
	};

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T									value_type;
			typedef Alloc								allocator_type;
			typedef value_type							&reference;
			typedef value_type							const &const_reference;
			typedef value_type							*pointer;
			typedef value_type							const *const_pointer;
			typedef _vector_iterator<T>					iterator;
			typedef _vector_iterator<const T>			const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	};
};

#endif
