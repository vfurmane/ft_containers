/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:05:21 by vfurmane          #+#    #+#             */
/*   Updated: 2022/03/15 17:35:06 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterator_traits.hpp"
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
			typedef	T										value_type;
			typedef Alloc									allocator_type;
			typedef value_type								&reference;
			typedef value_type								const &const_reference;
			typedef value_type								*pointer;
			typedef value_type								const *const_pointer;
			typedef _vector_iterator<T>						iterator;
			typedef _vector_iterator<const T>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
			typedef size_t size_type;

			explicit vector(const allocator_type &alloc = allocator_type()) : _n(0), _arr(NULL), _alloc(alloc)
			{
				_arr = _alloc.allocate(_n);
			}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _n(n), _arr(NULL), _alloc(alloc)
			{
				_arr = _alloc.allocate(_n);
				for (size_type i = 0; i < _n; i++)
				{
					_arr[i] = val;
				}
			}

		private:
			const size_type			_n;
			T						*_arr;
			allocator_type	_alloc;
	};
};

#endif
