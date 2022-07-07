/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:13:27 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/07 15:46:14 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef>
# include <functional>
# include <stdexcept>
# include "tree.hpp"
# include "utility.hpp"

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{
	
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;

		private:
			typedef ft::rb_tree<value_type, Compare> _rep_type;

		public:
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef value_type &								reference;
			typedef const value_type &							const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef typename _rep_type::iterator				iterator;
			typedef typename _rep_type::const_iterator			const_iterator;
			typedef typename _rep_type::reverse_iterator		reverse_iterator;
			typedef typename _rep_type::const_reverse_iterator	const_reverse_iterator;

			class value_compare
			{
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					bool	operator()(const value_type& lhs, const value_type& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}

				protected:
					Compare	comp;

					value_compare(Compare c) : comp(c)
					{
					}
			};
	
			map(void) : _alloc(), _tree()
			{
			}
			explicit map(const Compare &comp, const Allocator &alloc = Allocator()) : _alloc(alloc), _tree(comp)
			{
			}
			map(const map &obj)
			{
				*this = obj;
			}
			template<class InputIt>
			map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _alloc(alloc), _tree(comp)
			{
				while (first != last)
				{
					_tree.insert(*first);
					first++;
				}
			}
			~map(void)
			{
				typename _rep_type::node_type	z = _tree.header->left;
				while (z != _tree.header)
				{
					typename _rep_type::node_type	y = z->parent;
					delete z;
					if (y != _tree.header && y->right != NULL && y->right != z)
					{
						y = y->right;
						while (y->left != NULL)
							y = y->left;
					}
					z = y;
				}
				delete z;
			}
	
			map &operator=(const map &rhs)
			{
//				clear();
//				for (iterator it = begin(); it != end(); ++it)
//					_tree.insert(*it);
				(void)rhs;
				return *this;
			}

			allocator_type	get_allocator(void) const
			{
				return _alloc;
			}

			T	&at(const Key& key)
			{
				iterator it = _tree.lower_bound(key);
				if (it->first != key)
					throw std::out_of_range("map::at");
				return it->second;
			}
			const T	&at(const Key& key) const
			{
				iterator it = _tree.lower_bound(key);
				if (it->first != key)
					throw std::out_of_range("map::at");
				return it->second;
			}

			T	&operator[](const Key& key)
			{
				return _tree.insert(ft::make_pair(key, T()))->second;
			}

			iterator	begin(void)
			{
				return _tree.begin();
			}
			const_iterator	begin(void) const
			{
				return _tree.begin();
			}

			iterator	end(void)
			{
				return _tree.end();
			}
			const_iterator	end(void) const
			{
				return _tree.end();
			}

			reverse_iterator	rbegin(void)
			{
				return reverse_iterator(end());
			}
			const_reverse_iterator	rbegin(void) const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator	rend(void)
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator	rend(void) const
			{
				return const_reverse_iterator(begin());
			}

			bool	empty() const
			{
				return size() == 0;
			}

			size_type	size() const
			{
				return _tree.node_count;
			}

			size_type	max_size() const
			{
				return _alloc.max_size();
			}

			void	clear(void)
			{
				typename _rep_type::node_type	z = _tree.header->left;
				while (z != _tree.header)
				{
					typename _rep_type::node_type	y = z->parent;
					delete z;
					if (y != _tree.header && y->right != NULL && y->right != z)
					{
						y = y->right;
						while (y->left != NULL)
							y = y->left;
					}
					z = y;
				}
				_tree.node_count = 0;
				_tree.root = NULL;
				_tree.header->parent = NULL;
				_tree.header->left = _tree.header;
				_tree.header->right = _tree.header;
			}

			ft::pair<iterator, bool>	insert(const value_type& value)
			{
				size_type	pre_size = size();
				iterator node = _tree.insert(value);
				return make_pair(node, size() - pre_size);
			}

			iterator	insert(iterator hint, const value_type& value)
			{
				(void)hint;
				return insert(value).first;
			}

			template< class InputIt >
			void	insert(InputIt first, InputIt last)
			{
				while (first != last)
					insert(*first++);
			}
	
		private:
			Allocator	_alloc;
			_rep_type	_tree;
	};
}

#endif
