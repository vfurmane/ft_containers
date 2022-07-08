/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:20:44 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/08 13:41:25 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <cstddef>
# include <memory>
# include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"

namespace ft
{
	typedef enum 	e_color
	{
		RED,
		BLACK
	}				t_color;

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

	template <class T>
	class _tree_iterator
	{
		private:
			typedef ft::rb_tree_node<T> *		_base_ptr;

		public:
			template <class, class, class>
			friend struct rb_tree;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef value_type *				pointer;
			typedef value_type &				reference;
			typedef bidirectional_iterator_tag	iterator_category;

			_tree_iterator(void) : _node()
			{
			}
			_tree_iterator(_base_ptr ptr) : _node(ptr)
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

			reference	operator*()
			{
				return _node->value;
			}

			pointer	operator->(void)
			{
				return &_node->value;
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
					_base_ptr	y = _node->parent;
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
					_base_ptr y = _node->left;
					while (y->right != NULL)
						y = y->right;
					_node = y;
				}
				else
				{
					_base_ptr y = _node->parent;
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
			_base_ptr	_node;
	};

	template < class T, class Compare, class Allocator = std::allocator< rb_tree_node<T> > >
	struct rb_tree
	{
		typedef rb_tree_node<T>							value_type;
		typedef	std::allocator<value_type>				allocator;
		typedef value_type 								&reference;
		typedef const value_type						&const_reference;
		typedef typename allocator::pointer				node_type;
		typedef typename allocator::const_pointer		const_node_type;
		typedef	_tree_iterator<T>						iterator;
		typedef	_tree_iterator<const T>					const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef std::size_t								size_type;

		Compare				key_compare;
		node_type			root;
		node_type			header;
		size_type			node_count;

		rb_tree(void) : key_compare(), root(NULL), header(new value_type), node_count(0)
		{
			header->color = RED;
			header->parent = root;
			header->left = header;
			header->right = header;
		}
		rb_tree(const Compare &comp) : key_compare(comp), root(NULL), header(new value_type), node_count(0)
		{
			header->color = RED;
			header->parent = root;
			header->left = header;
			header->right = header;
		}
		rb_tree(const rb_tree &obj) : key_compare(), root(), header(), node_count(0)
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

		node_type	left_rotate_tree(node_type node, node_type parent)
		{
			node_type	old_root = node;
			node = node->right;
			node->parent = old_root->parent;
			node_type	y = node->left;
			node->left = old_root;
			old_root->right = y;
			old_root->parent = node;
			if (parent != header)
			{
				if (parent->left == old_root)
					parent->left = node;
				else
					parent->right = node;
			}
			return node;
		}

		node_type	right_rotate_tree(node_type node, node_type parent)
		{
			node_type	old_root = node;
			node = node->left;
			node->parent = old_root->parent;
			node_type	y = node->right;
			node->right = old_root;
			old_root->left = y;
			old_root->parent = node;
			if (parent != header)
			{
				if (parent->left == old_root)
					parent->left = node;
				else
					parent->right = node;
			}
			return node;
		}

		void	balance_tree(node_type node)
		{
			while (node->parent->color == RED)
			{
				if (node->parent == node->parent->parent->left)
				{
					node_type	y = node->parent->parent->right;
					if (y != NULL && y->color == RED)
					{
						node->parent->color = BLACK;
						y->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							node = left_rotate_tree(node, node->parent);
						}
						else
						{
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = right_rotate_tree(node->parent->parent, node->parent->parent->parent);
						}
						if (node->parent == header)
						{
							root = node;
							header->parent = node;
						}
					}
				}
				else
				{
					node_type	y = node->parent->parent->left;
					if (y != NULL && y->color == RED)
					{
						node->parent->color = BLACK;
						y->color = BLACK;
						node->parent->parent->color = RED;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							node = node->parent;
							node = right_rotate_tree(node, node->parent);
						}
						else
						{
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = left_rotate_tree(node->parent->parent, node->parent->parent->parent);
						}
						if (node->parent == header)
						{
							root = node;
							header->parent = node;
						}
					}
				}
			}
			root->color = BLACK;
		}

		iterator	insert(const T& value)
		{
			if (root == NULL)
			{
				root = new value_type(value);
				root->color = BLACK;
				root->parent = header;
				header->parent = root;
				header->left = root;
				header->right = root;
				node_count++;
				return root;
			}
			iterator it = lower_bound(value.first);
			if (it->first == value.first)
				return it;
			node_type	z = root;
			bool		direction;
			node_type	node;
			while (z != NULL)
			{
				direction = key_compare(value.first, z->value.first);
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
			balance_tree(node);
			header->color = RED;
			node_count++;
			return node;
		}

		void	erase(iterator _node)
		{
			node_type	node = _node._node;
			if (header->left == node)
				header->left = node->parent;
			if (header->right == node)
				header->right = node->parent;
			// if no child
			if (node->left == NULL && node->right == NULL)
			{
				if (root == node)
				{
					root = NULL;
					header->left = header;
					header->right = header;
				}
				else if (node->parent->left == node)
					node->parent->left = NULL;
				else
					node->parent->right = NULL;
			}
			else if (node->right == NULL)
			{
				if (root == node)
					root = node->left;
				else
				{
					node->left->parent = node->parent;
					if (node->parent->right == node)
						node->parent->right = node->left;
					else
						node->parent->left = node->left;
					if (root == node)
						root = node;
				}
			}
			else if (node->left == NULL)
			{
				if (root == node)
					root = node->right;
				else
				{
					node->right->parent = node->parent;
					if (node->parent->left == node)
						node->parent->left = node->right;
					else
						node->parent->right = node->right;
				}
			}
			// if two children
			else
			{
				node_type	smallest_right = node->right;
				while (smallest_right->left != NULL)
					smallest_right = smallest_right->left;
				if (smallest_right != node->right)
				{
					smallest_right->parent->left = NULL;
					smallest_right->right = node->right;
				}
				node->left->parent = smallest_right;
				node->right->parent = smallest_right;
				smallest_right->left = node->left;
				smallest_right->parent = node->parent;
				if (node == root)
					root = smallest_right;
				else if (node->parent->right == node)
					node->parent->right = smallest_right;
				else
					node->parent->left = smallest_right;
			}
			header->parent = root;
			if (header->left->left != NULL)
				header->left = header->left->left;
			if (header->right->right != NULL)
				header->right = header->right->right;
			node_count--;
			delete &(*node);
		}

		iterator	lower_bound(const typename T::first_type &key)
		{
			node_type	node = root;
			node_type	greater = node->parent;
			while (node != NULL)
			{
				if (key_compare(node->value.first, key))
					node = node->right;
				else
				{
					greater = node;
					node = node->left;
				}
			}
			return iterator(greater);
		}
		const_iterator	lower_bound(const typename T::first_type &key) const
		{
			node_type	node = root;
			node_type	greater = node->parent;
			while (node != NULL)
			{
				if (key_compare(node->value.first, key))
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
