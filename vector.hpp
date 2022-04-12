/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:05:21 by vfurmane          #+#    #+#             */
/*   Updated: 2022/04/12 15:11:38 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stdexcept>
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

			explicit vector(const allocator_type &alloc = allocator_type()) : _n(0), _capacity(0), _arr(NULL), _alloc(alloc)
			{
				_arr = _alloc.allocate(_n);
			}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _n(0), _capacity(0), _arr(NULL), _alloc(alloc)
			{
				_dispatch_ctr(n, val, ft::true_type());
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _n(0), _capacity(0), _arr(NULL), _alloc(alloc)
			{
				_dispatch_ctr(first, last, typename ft::is_integral<InputIterator>::type());
			}
			vector (const vector &x) : _n(x._n), _capacity(0), _arr(NULL), _alloc(x._alloc)
			{
				_dispatch_ctr(x._arr, x._arr + x._n, ft::false_type());
			}
			~vector()
			{
				_alloc.deallocate(_arr, capacity());
			}

			vector &operator=(const vector &x)
			{
				_alloc.deallocate(_arr, _n);
				_alloc = x._alloc;
				_dispatch_ctr(x._arr, x._arr + x._n, ft::false_type());
				return *this;
			}

			size_type size() const
			{
				return _n;
			}

			size_type max_size() const
			{
				return _alloc.max_size();
			}

			void resize(size_type n, value_type val = value_type())
			{
				T* current_arr;
				size_type i = 0;

				if (n > capacity())
					current_arr = _alloc.allocate(n);
				else
					current_arr = _arr;
				while (i < size() && i < n)
				{
					current_arr[i] = _arr[i];
					i++;
				}
				while (i < n)
					current_arr[i++] = val;
				if (n > capacity())
				{
					_alloc.deallocate(_arr, capacity());
					_capacity = n;
				}
				_arr = current_arr;
				_n = n;
			}

			size_type capacity() const
			{
				return _capacity;
			}

			bool empty() const
			{
				return size() == 0;
			}

			reference operator[] (size_type n)
			{
				return _arr[n];
			}
			const_reference operator[] (size_type n) const
			{
				return _arr[n];
			}

			reference at(size_type n)
			{
				if (n >= _n) throw std::out_of_range("n is out of bounds");
				return (*this)[n];
			}
			const_reference at(size_type n) const
			{
				if (n >= _n) throw std::out_of_range("n is out of bounds");
				return (*this)[n];
			}

			reference front()
			{
				return (*this)[0];
			}
			const_reference front() const
			{
				return (*this)[0];
			}

			reference back()
			{
				return (*this)[_n - 1];
			}
			const_reference back() const
			{
				return (*this)[_n - 1];
			}

		private:
			size_type		_n;
			size_type		_capacity;
			T			   	*_arr;
			allocator_type	_alloc;

			void	_dispatch_ctr(size_type n, const value_type &val, ft::true_type sub)
			{
				(void)sub;
				_n = n;
				_capacity = _n;
				_arr = _alloc.allocate(_n);
				for (size_type i = 0; i < _n; i++)
				{
					_arr[i] = val;
				}
			}
			template <class InputIterator>
			void	_dispatch_ctr(InputIterator first, InputIterator last, ft::false_type sub)
			{
				(void)sub;
				for (InputIterator it = first; it != last; it++)
					_n++;
				_arr = _alloc.allocate(_n);
				_capacity = _n;
				size_type i = 0;
				for (InputIterator it = first; it != last; it++)
					_arr[i++] = *it;
			}
	};
};

#endif
