/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:05:21 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/22 14:11:04 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <algorithm>
# include <cstring>
# include <memory>
# include <stdexcept>
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template<bool B, class T = void>
	struct enable_if {};
	 
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<typename, typename>
    struct is_same
    {
      enum { value = 0 };
      typedef false_type type;
    };

	template<typename _Tp>
    struct is_same<_Tp, _Tp>
    {
      enum { value = 1 };
      typedef true_type type;
    };
	template <class Iterator, class Container>
	class _vector_iterator : public iterator<ft::random_access_iterator_tag, typename Container::value_type> {
		public:
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

			_vector_iterator(void) : _ptr(NULL)
			{
			}
			~_vector_iterator(void)
			{
			}
			template <class Iter>
			_vector_iterator(const _vector_iterator<Iter, typename enable_if<
					is_same<
						Iter,
						typename Container::pointer
					>::value, Container
			>::type> &iter) : _ptr(iter.base())
			{
			}
			_vector_iterator(Iterator ptr) : _ptr(ptr)
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
			reference	operator*()
			{
				return *_ptr;
			}
			pointer		operator->()
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
			typename Container::value_type	&operator[](int n)
			{
				return _ptr[n];
			}

			const Iterator	&base(void) const
			{
				return _ptr;
			}

		private:
			Iterator	_ptr;
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
			typedef _vector_iterator<pointer, vector>						iterator;
			typedef _vector_iterator<const_pointer, vector>			const_iterator;
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
				_alloc = x._alloc;
				_dispatch_assign(x.begin(), x.end(), ft::false_type());
				return *this;
			}

			iterator begin()
			{
				return iterator(&front());
			}
			const_iterator begin() const
			{
				return const_iterator(&front());
			}
			iterator end()
			{
				return iterator(&back() + 1);
			}
			const_iterator end() const
			{
				return const_iterator(&back() + 1);
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
				return size_type(_n);
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
					current_arr = _alloc.allocate(n < capacity() * 2 ? capacity() * 2 : n);
				else
					current_arr = _alloc.allocate(capacity());
				while (i < size() && i < n)
				{
					_alloc.construct(&current_arr[i], _arr[i]);
					i++;
				}
				while (i < n)
					_alloc.construct(&current_arr[i++], val);
				i = 0;
				if (n > capacity())
				{
					while (i < size())
						_alloc.destroy(&_arr[i++]);
					_alloc.deallocate(_arr, capacity());
					_capacity = n < capacity() * 2 ? capacity() * 2 : n;
				}
				else
				{
					while (i < size())
						_alloc.destroy(&_arr[i++]);
					_alloc.deallocate(_arr, capacity());
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

			void reserve(size_type n)
			{
				if (n <= capacity()) return ;
				if (n > _alloc.max_size()) throw std::length_error("vector::reserve") ;

				T* current_arr = _alloc.allocate(n);
				size_type i = 0;

				while (i < size())
				{
					_alloc.construct(&current_arr[i], _arr[i]);
					i++;
				}
				i = 0;
				while (i < size())
					_alloc.destroy(&_arr[i++]);
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
				_dispatch_assign(n, val, ft::true_type());
			}
			void push_back(const value_type& val)
			{
				if (size() >= capacity())
				{
					T* 			new_arr;
					size_type	new_cap = capacity() * 2;

					if (new_cap == 0) new_cap = 1;
					new_arr = _alloc.allocate(new_cap);
					for (size_type i = 0; i < size(); i++)
						_alloc.construct(&new_arr[i], _arr[i]);
					_alloc.construct(&new_arr[size()], val);
					for (size_type i = 0; i < size(); i++)
						_alloc.destroy(&_arr[i]);
					_alloc.deallocate(_arr, capacity());
					_capacity = new_cap;
					_arr = new_arr;
				}
				else
					_alloc.construct(&_arr[size()], val);
				_n++;
			}

			void pop_back()
			{
				_alloc.destroy(&this->back());
				_n--;
			}

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
					for (iterator it = begin(); it != end() + 1; ++it)
					{
						if (it == position)
						{
							_alloc.construct(&new_arr[i], val);
							position = &new_arr[i];
							it--;
						}
						else if (it != end())
							new_arr[i] = *it;
						i++;
					}
					_alloc.deallocate(_arr, capacity());
					_capacity = new_cap;
					_arr = new_arr;
				}
				else
				{
					if (!empty())
					{
						_alloc.construct(&(*end()), *(end() - 1));
						std::copy_backward(position, end(), end() + 1);
					}
					_alloc.construct(&(*position), val);
				}
				_n++;
				return position;
			}
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

			void	clear()
			{
				for (iterator it = begin(); it != end(); ++it)
					_alloc.destroy(&(*it));
				_n = 0;
			}

			allocator_type	get_allocator() const
			{
				return _alloc;
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
					current_arr = _alloc.allocate(capacity());
				size_t	i = 0;
				for (InputIterator it = first; it != last; ++it)
					_alloc.construct(&current_arr[i++], *it);
				for (iterator it = begin(); it != end(); ++it)
					_alloc.destroy(&(*it));
				_alloc.deallocate(_arr, capacity());
				if (n > capacity())
					_capacity = n;
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
					current_arr = _alloc.allocate(capacity());
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&current_arr[i], val);
				for (size_type i = 0; i < size(); i++)
					_alloc.destroy(&_arr[i]);
				_alloc.deallocate(_arr, capacity());
				if (n > capacity())
					_capacity = n;
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
					size_type	new_cap = size() * 2;

					if (new_cap < size() + n)
						new_cap = size() + n;
					new_arr = _alloc.allocate(new_cap);
					size_type i = 0;
					for (iterator it = begin(); it != end() + 1; ++it)
					{
						if (it == position)
						{
							for (size_type j = 0; j < n; j++)
								_alloc.construct(&new_arr[i++], val);
							position = &new_arr[i];
							it--;
						}
						else if (it != end())
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
					if (!empty())
					{
						for (iterator it = end(); it != end() + n; ++it)
							_alloc.construct(&(*it), *(end() - 1));
						std::copy_backward(position, end(), end() + n);
					}
					for (size_type i = 0; i < n; i++)
						_alloc.construct(&position[i], val);
				}
				_n += n;
			}
			template <class InputIterator>
			void	_dispatch_insert(iterator position, InputIterator first, InputIterator last, ft::false_type sub)
			{	(void)sub;
				(void)sub;
				size_type	range = last - first;
				if (range == 1)
					return static_cast<void>(insert(position, *first));
				if (size() + range > capacity())
				{
					T* 			new_arr;
					size_type	new_cap = size() * 2;

					if (new_cap < size() + range)
						new_cap = size() + range;
					new_arr = _alloc.allocate(new_cap);
					size_type i = 0;
					for (iterator it = begin(); it != end() + 1; ++it)
					{
						if (it == position)
						{
							for (InputIterator input_it = first; input_it != last; ++input_it)
								_alloc.construct(&new_arr[i++], *input_it);
							position = &new_arr[i];
							it--;
						}
						else if (it != end())
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
					if (!empty())
					{
						for (iterator it = end(); it != end() + range; ++it)
							_alloc.construct(&(*it), *(end() - 1));
						std::copy_backward(position, end(), end() + range);
					}
					size_t	i = 0;
					for (InputIterator it = first; it != last; ++it)
						_alloc.construct(&position[i++], *it);
				}
				_n += range;
			}
	};

	template<class T, class Alloc>
	bool	operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T,Alloc>::const_iterator	l_it = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator	r_it = rhs.begin();
		typename ft::vector<T,Alloc>::const_iterator	l_end = lhs.end();
		typename ft::vector<T,Alloc>::const_iterator	r_end = rhs.end();
		while (l_it != l_end && r_it != r_end)
		{
			if (*l_it != *r_it)
				return false;
			l_it++;
			r_it++;
		}
		return true;
	}
	template<class T, class Alloc>
	bool	operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template<class T, class Alloc>
	bool	operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return lhs.size() < rhs.size();
		typename ft::vector<T,Alloc>::const_iterator	l_it = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator	r_it = rhs.begin();
		typename ft::vector<T,Alloc>::const_iterator	l_end = lhs.end();
		typename ft::vector<T,Alloc>::const_iterator	r_end = rhs.end();
		while (l_it != l_end && r_it != r_end)
		{
			if (*l_it < *r_it)
				return true;
			l_it++;
			r_it++;
		}
		return false;
	}
	template<class T, class Alloc>
	bool	operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs > rhs);
	}
	template<class T, class Alloc>
	bool	operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return rhs < lhs;
	}
	template<class T, class Alloc>
	bool	operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
};

#endif
