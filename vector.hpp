/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:05:21 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/09 11:30:37 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstring>
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T>
	class _vector_iterator : public iterator<ft::random_access_iterator_tag, T> {
		public:
			_vector_iterator(void) : _ptr(NULL)
			{
			}
			~_vector_iterator(void)
			{
			}
			_vector_iterator(const _vector_iterator &obj) : _ptr(NULL)
			{
				*this = obj;
			}
			_vector_iterator(T *ptr) : _ptr(ptr)
			{
			}

			_vector_iterator	&operator=(const _vector_iterator &rhs)
			{
				_ptr = rhs._ptr;
				return *this;
			}
			bool	operator==(const _vector_iterator &rhs)
			{
				return _ptr == rhs._ptr;
			}
			bool	operator!=(const _vector_iterator &rhs)
			{
				return _ptr != rhs._ptr;
			}
			T	&operator*()
			{
				return *_ptr;
			}
			T	*operator->()
			{
				return _ptr;
			}
			_vector_iterator	operator++()
			{
				_ptr++;
				return *this;
			}
			_vector_iterator	operator++(int)
			{
				_vector_iterator tmp(*this);
				_ptr++;
				return tmp;
			}
			_vector_iterator	operator--()
			{
				_ptr--;
				return *this;
			}
			_vector_iterator	operator--(int)
			{
				_vector_iterator tmp(*this);
				_ptr--;
				return tmp;
			}
			_vector_iterator	operator+(int n)
			{
				_vector_iterator tmp(*this);
				tmp._ptr += n;
				return tmp;
			}
			friend _vector_iterator	operator+(int n, const _vector_iterator &rhs)
			{
				_vector_iterator tmp(rhs);
				tmp._ptr += n;
				return tmp;
			}
			_vector_iterator	operator-(int n)
			{
				_vector_iterator tmp(*this);
				tmp._ptr -= n;
				return tmp;
			}
			int	operator-(const _vector_iterator &rhs)
			{
				return _ptr - rhs._ptr;
			}
			bool				operator<(const _vector_iterator &rhs)
			{
				return _ptr < rhs._ptr;
			}
			bool				operator>(const _vector_iterator &rhs)
			{
				return _ptr > rhs._ptr;
			}
			bool				operator<=(const _vector_iterator &rhs)
			{
				return _ptr <= rhs._ptr;
			}
			bool				operator>=(const _vector_iterator &rhs)
			{
				return _ptr >= rhs._ptr;
			}
			_vector_iterator	operator+=(int n)
			{
				_ptr += n;
				return *this;
			}
			_vector_iterator	operator-=(int n)
			{
				_ptr -= n;
				return *this;
			}
			T	&operator[](int n)
			{
				return _ptr[n];
			}

		private:
			T*	_ptr;
	};

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T														value_type;
			typedef Alloc													allocator_type;
			typedef value_type												&reference;
			typedef value_type												const &const_reference;
			typedef value_type												*pointer;
			typedef value_type												const *const_pointer;
			typedef _vector_iterator<T>										iterator;
			typedef _vector_iterator<const T>								const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t													size_type;

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
			vector (const vector &x) : _n(0), _capacity(0), _arr(NULL), _alloc(x._alloc)
			{
				_dispatch_ctr(x._arr, x._arr + x._n, ft::false_type());
			}
			~vector()
			{
				for (size_type i = 0; i < size(); i++)
					_alloc.destroy(&_arr[i]);
				_alloc.deallocate(_arr, capacity());
			}

			vector &operator=(const vector &x)
			{
				// for (iterator it = begin(); it != end(); ++it)
				// 	_alloc.destroy(&(*it));
				// _alloc.deallocate(_arr, _n);
				// _n = 0;
				// _dispatch_ctr(x.begin(), x.end(), ft::false_type());
				_alloc = x._alloc;
				_dispatch_assign(x.begin(), x.end(), ft::false_type());
				return *this;
			}

			iterator begin()
			{
				return &front();
			}
			const_iterator begin() const
			{
				return &front();
			}
			iterator end()
			{
				return &back() + 1;
			}
			const_iterator end() const
			{
				return &back() + 1;
			}
			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}
			const_reverse_iterator rbegin() const
			{
				return reverse_iterator(end());
			}
			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const
			{
				return reverse_iterator(begin());
			}

			size_type size() const
			{
				return difference_type(end() - begin());
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
				while (i < size())
					_alloc.destroy(&current_arr[i++]);
				while (i < n)
					_alloc.construct(&current_arr[i++], val);
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

			void reserve (size_type n)
			{
				if (n <= capacity()) return ;

				T* current_arr = _alloc.allocate(n);
				size_type i = 0;

				while (i < size())
				{
					_alloc.construct(&current_arr[i], _arr[i]);
					i++;
				}
				_alloc.deallocate(_arr, capacity());
				_arr = current_arr;
				_capacity = n;
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

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				_dispatch_assign(first, last, typename ft::is_integral<InputIterator>::type());
			}
			void assign(size_type n, const value_type& val = value_type())
			{
				_dispatch_assign(n, val, typename ft::false_type());
			}
			void push_back (const value_type& val)
			{
				if (size() >= capacity())
				{
					T* 			new_arr;
					size_type	new_cap = capacity() * 2;

					if (new_cap == 0) new_cap = 1;
					new_arr = _alloc.allocate(new_cap);
					for (size_type i = 0; i < size(); i++)
						new_arr[i] = _arr[i];
					_alloc.deallocate(_arr, capacity());
					_capacity = new_cap;
					_arr = new_arr;
				}
				_alloc.construct(&_arr[size()], val);
				_n++;
			}

			void pop_back()
			{
				_alloc.destroy(&this->back());
				_n--;
			}

			// WHEN THE CAPACITY IS SUFFICIENT ???
			iterator insert(iterator position, const value_type& val)
			{
				if (position == end())
				{
					push_back(val);
					return end() - 1;
				}
				if (size() >= capacity())
				{
					T* 			new_arr;
					size_type	new_cap = capacity() * 2;

					if (new_cap == 0) new_cap = 1;
					new_arr = _alloc.allocate(new_cap);
					size_type i = 0;
					for (iterator it = begin(); it != end(); ++it)
					{
						if (it == position)
						{
							_alloc.construct(&new_arr[i], val);
							position = &new_arr[i];
							it--;
						}
						else
							new_arr[i] = *it;
						i++;
					}
					_alloc.deallocate(_arr, capacity());
					_capacity = new_cap;
					_arr = new_arr;
					_n++;
				}
				return position;
			}
			// inserting 0 element
			// inserting 0 element on a size 0 vector
			void insert(iterator position, size_type n, const value_type& val)
			{
				_dispatch_insert(position, n, val, typename ft::true_type());
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				_dispatch_insert(position, first, last, typename ft::is_integral<InputIterator>::type());
			}

			iterator	erase(iterator position)
			{
				std::copy(position + 1, end(), position);
				_alloc.destroy(&back());
				_n--;
				return position;
			}
			iterator	erase(iterator first, iterator last)
			{
				iterator position = std::copy(last, end(), first);
				for (iterator it = position; it != end(); ++it)
					_alloc.destroy(&(*it));
				_n -= last - first;
				return first;
			}

			void	swap(vector& x)
			{
				T	*tmp_arr = _arr;
				_arr = x._arr;
				x._arr = tmp_arr;

				size_type	tmp_n = _n;
				_n = x._n;
				x._n = tmp_n;

				size_type tmp_capacity = _capacity;
				_capacity = x._capacity;
				x._capacity = tmp_capacity;
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
					_alloc.construct(&_arr[i], val);
				}
			}
			template <class InputIterator>
			void	_dispatch_ctr(InputIterator first, InputIterator last, ft::false_type sub)
			{
				(void)sub;
				_n += last - first;
				_arr = _alloc.allocate(_n);
				_capacity = _n;
				size_type i = 0;
				for (InputIterator it = first; it != last; it++)
					_alloc.construct(&_arr[i++], *it);
			}

			template <class InputIterator>
			void	_dispatch_assign(InputIterator first, InputIterator last, ft::false_type sub)
			{
				(void)sub;
				T* current_arr;
				size_t	n = last - first;
				if (n > capacity())
					current_arr = _alloc.allocate(n);
				else
					current_arr = _arr;
				size_t	i = 0;
				for (InputIterator it = first; it != last; it++)
					_alloc.construct(&current_arr[i++], *it);
				if (n > capacity())
				{
					for (iterator it = begin(); it != end(); ++it)
						_alloc.destroy(&(*it));
					_alloc.deallocate(_arr, capacity());
					_capacity = n;
				}
				_arr = current_arr;
				_n = n;
			}
			void	_dispatch_assign(size_type n, const value_type &val, ft::true_type sub)
			{
				(void)sub;
				T* current_arr;

				if (n > capacity())
					current_arr = _alloc.allocate(n);
				else
					current_arr = _arr;
				for (size_type i = 0; i < n; i++)
					current_arr[i] = val;
				if (n > capacity())
				{
					_alloc.deallocate(_arr, capacity());
					_capacity = n;
				}
				_arr = current_arr;
				_n = n;
			}

			void	_dispatch_insert(iterator position, size_type n, const value_type &val, ft::true_type sub)
			{
				(void)sub;
				if (n == 0)
					return ;
				else if (n == 1)
					return static_cast<void>(insert(position, val));
				if (size() + n > capacity())
				{
					T* 			new_arr;
					size_type	new_cap = capacity() * 2;

					if (new_cap < size() + n)
						new_cap = size() + n;
					new_arr = _alloc.allocate(new_cap);
					size_type i = 0;
					for (iterator it = begin(); it != end(); ++it)
					{
						if (it == position)
						{
							for (size_type j = 0; j < n; j++)
								_alloc.construct(&new_arr[i++], val);
							position = &new_arr[i]; // wrong : i has moved
							it--;
						}
						else
							_alloc.construct(&new_arr[i++], *it);
					}
					for (iterator it = begin(); it != end(); ++it)
						_alloc.destroy(&(*it));
					_alloc.deallocate(_arr, capacity());
					_capacity = new_cap;
					_arr = new_arr;
				}
				else
				{
					std::copy_backward(position, end(), end() + n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&position[i], val);
				}
				_n += n;
			}
			template <class InputIterator>
			void	_dispatch_insert(iterator position, InputIterator first, InputIterator last, ft::false_type sub)
			{
				(void)sub;
				size_type	range = last - first;
				if (range == 1)
					return static_cast<void>(insert(position, *first));
				if (size() + range > capacity())
				{
					T* 			new_arr;
					size_type	new_cap = capacity() * 2;

					if (new_cap < size() + range)
						new_cap = size() + range;
					new_arr = _alloc.allocate(new_cap);
					size_type i = 0;
					for (iterator it = begin(); it != end(); ++it)
					{
						if (it == position)
						{
							for (InputIterator input_it = first; input_it != last; ++input_it)
								_alloc.construct(&new_arr[i++], *input_it);
							position = &new_arr[i];
							it--;
						}
						else
							_alloc.construct(&new_arr[i++], *it);
					}
					for (iterator it = begin(); it != end(); ++it)
						_alloc.destroy(&(*it));
					_alloc.deallocate(_arr, capacity());
					_capacity = new_cap;
					_arr = new_arr;
				}
				else
				{
					std::copy_backward(position, end(), end() + range);
					size_t	i = 0;
					for (InputIterator it = first; it != last; ++it)
						_alloc.construct(&position[i++], *it);
				}
				_n += range;
			}
	};
};

#endif
