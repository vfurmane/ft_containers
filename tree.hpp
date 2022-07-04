/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:20:44 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/04 13:27:56 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <cstddef>
# include <memory>
# include "iterator.hpp"

namespace ft
{
	typedef enum 	e_color
	{
		RED,
		BLACK
	}				t_color;

	template <class Iterator, class Container>
	class _tree_iterator: public ft::iterator<ft::random_access_iterator_tag, typename Container::value_type>
	{
		public:
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;

			_tree_iterator(Iterator ptr) : _node(ptr)
			{
			}
			_tree_iterator(const _tree_iterator& obj) : _node()
			{
				*this = obj;
			}
			~_tree_iterator(void)
			{
			}

			_tree_iterator	&operator=(const _tree_iterator &obj)
			{
				_node = obj._node;
				return *this;
			}

			bool		operator==(const _tree_iterator &rhs)
			{
				return _node == rhs._node;
			}

			bool		operator!=(const _tree_iterator &rhs)
			{
				return !(*this == rhs);
			}

			reference	&operator*()
			{
				return *_node;
			}

			pointer	operator->(void)
			{
				return _node;
			}

			_tree_iterator	&operator++()
			{
				if (_node->right != NULL)
				{
					_node = _node->right;
					while (_node->left != NULL)
						_node = _node->left;
				}
				else
				{
					Iterator	y = _node->parent;
					while (_node == y->right)
					{
						_node = y;
						y = y->parent;
					}
					if (_node->right != y)
						_node = y;
				}
				return *this;
			}
			_tree_iterator	operator++(int)
			{
				_tree_iterator	tmp(*this);
				++(*this);
				return tmp;
			}

			_tree_iterator& operator--()
			{
				if (_node->color == RED && _node->parent->parent == _node)  
					_node = _node->right;
				else if (_node->left != NULL)
				{
					Iterator y = _node->left;
					while (y->right != NULL)
						y = y->right;
					_node = y;
				}
				else
				{
					Iterator y = _node->parent;
					while (_node == y->left)
					{
						_node = y;
						y = y->parent;
					}
					_node = y;
				}
				return *this;
			}
			_tree_iterator	operator--(int)
			{
				_tree_iterator	tmp(*this);
				--(*this);
				return tmp;
			}

		private:
			Iterator	_node;
	};

	template <typename T>
	struct	rb_tree_node
	{
		T				value;
		t_color			color;
		rb_tree_node	*parent;
		rb_tree_node	*left;
		rb_tree_node	*right;

		rb_tree_node(void) : value(), color(BLACK), parent(NULL), left(NULL), right(NULL)
		{
		}
		rb_tree_node(const T &val) : value(val), color(RED), parent(NULL), left(NULL), right(NULL)
		{
		}
		rb_tree_node(const rb_tree_node &obj) : value(), color(), parent(NULL), left(NULL), right(NULL)
		{
			*this = obj;
		}
		~rb_tree_node()
		{
		}

		rb_tree_node	&operator=(const rb_tree_node &rhs)
		{
			value = rhs.value;
			parent = rhs.parent;
			left = rhs.left;
			right = rhs.right;
			return *this;
		}
	};

	template < class T, class Compare, class Allocator = std::allocator< rb_tree_node<T> > >
	struct rb_tree
	{
		typedef rb_tree_node<T>								value_type;
		typedef	std::allocator<value_type>					allocator;
		typedef value_type 									&reference;
		typedef const value_type							&const_reference;
		typedef typename allocator::pointer					node_type;
		typedef typename allocator::const_pointer			const_node_type;
		typedef	_tree_iterator<node_type, rb_tree>			iterator;
		typedef	_tree_iterator<const_node_type, rb_tree>	const_iterator;

		Compare				key_compare;
		node_type			root;
		node_type			header;

		rb_tree(void) : root(NULL), header(new value_type)
		{
			header->color = RED;
			header->parent = root;
			header->left = header;
			header->right = header;
		}
		rb_tree(const rb_tree &obj) : rb_tree()
		{
			*this = obj;
		}
		~rb_tree(void)
		{
		}

		rb_tree	&operator=(const rb_tree &rhs)
		{
			root = rhs.root; // deep copy plsss
			return *this;
		}

		iterator	begin(void)
		{
			return iterator(leftmost());
		}
		const_iterator	begin(void) const
		{
			return const_iterator(leftmost());
		}

		iterator	end(void)
		{
			return iterator(header);
		}
		const_iterator	end(void) const
		{
			return const_iterator(header);
		}

		void	insert(const T& value)
		{
			if (root == NULL)
			{
				root = new value_type(value);
				root->parent = header;
				header->parent = root;
				header->left = root;
				header->right = root;
				return ;
			}
			node_type	z = root;
			bool		direction;
			node_type	node;
			while (z != NULL)
			{
				direction = key_compare(value, z->value);
				node = direction ? z->left : z->right;
				if (node == NULL || node == header)
					break ;
				z = node;
			}
			(direction ? z->left : z->right) = new value_type(value);
			node = (direction ? z->left : z->right);
			node->parent = z;
			if (header->left->left != NULL)
				header->left = header->left->left;
			if (header->right->right != NULL)
				header->right = header->right->right;
		}

		iterator	lower_bound(const T& key)
		{
			node_type	node = root;
			node_type	greater = node->parent;
			while (node != NULL)
			{
				if (key_compare(node->value, key))
					node = node->right;
				else
				{
					greater = node;
					node = node->left;
				}
			}
			return iterator(greater);
		}
		const_iterator	lower_bound(const T& key) const
		{
			node_type	node = root;
			node_type	greater = node->parent;
			while (node != NULL)
			{
				if (key_compare(node->value, key))
					node = node->right;
				else
				{
					greater = node;
					node = node->left;
				}
			}
			return const_iterator(greater);
		}

		node_type	leftmost()
		{
			return header->left;
		}

		node_type	rightmost()
		{
			return header->right;
		}
	};
};

#endif
