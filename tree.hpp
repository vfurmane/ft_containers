/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:20:44 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/30 17:39:40 by vfurmane         ###   ########.fr       */
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
		BLACK,
		NIL
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
			_tree_iterator(const _tree_iterator& obj) : _node(obj._node)
			{
			}
			~_tree_iterator(void)
			{
			}

			_tree_iterator	&operator=(const _tree_iterator &obj)
			{
				(void)obj;
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

			_tree_iterator	operator++()
			{
				if (_node->_right->_color != NIL) {
					_node = _node->_right;
					while (_node->_left->_color != NIL)
						_node = _node->_left;
				} else {
					Iterator	y = _node->_parent;
					while (_node == y->_right) {
						_node = y;
						y = y->_parent;
					}
					if (_node->_right != y)
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

		private:
			Iterator	_node;
	};
	template <class T>
	struct _rb_tree_node
	{
		T				_value;
		e_color			_color;
		_rb_tree_node	*_parent;
		_rb_tree_node	*_left;
		_rb_tree_node	*_right;

		_rb_tree_node(void) : _value(T()), _color(NIL), _parent(NULL), _left(NULL), _right(NULL)
		{
		}
		_rb_tree_node(const T& value) : _value(value), _color(RED), _parent(new _rb_tree_node), _left(new _rb_tree_node), _right(new _rb_tree_node)
		{
			_left->_parent = this;
			_right->_parent = this;
		}
		_rb_tree_node(const _rb_tree_node &obj) : _value(), _color(obj._color), _parent(NULL), _left(NULL), _right(NULL) // initialise parent and children ?
		{
			*this = obj;
		}
		~_rb_tree_node(void)
		{
		}

		_rb_tree_node	&operator=(const _rb_tree_node &rhs)
		{
			_value = rhs._value;
			_color = rhs._color;
			_left = rhs._left;
			_right = rhs._right;
			_parent = rhs._parent;
			return *this;
		}
	};

	template < class T, class Alloc = std::allocator< _rb_tree_node<T> >, class Compare = std::less<T> >
	class _rb_tree
	{
		public:
			typedef _rb_tree_node<T>						value_type;
			typedef value_type 								&reference;
			typedef const value_type						&const_reference;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;
			typedef	_tree_iterator<pointer, _rb_tree>		iterator;
			typedef	_tree_iterator<const_pointer, _rb_tree>	const_iterator;

			Compare	key_compare;

			_rb_tree(void) : _root(new value_type())
			{
			}
			_rb_tree(const _rb_tree &obj) : _root(new value_type())
			{
				*this = obj;
			}
			~_rb_tree(void)
			{
			}

			_rb_tree	&operator=(const _rb_tree &rhs)
			{
				_root = rhs._root; // deep copy plsss
				return *this;
			}

			iterator	begin(void)
			{
				return iterator(&leftmost());
			}

			iterator	end(void)
			{
				return ++iterator(&rightmost());
			}

			void	insert(const T& value)
			{
				if (_root->_color == NIL)
				{
					*_root = value_type(value);
					_root->_parent = NULL;
					return ;
				}
				pointer	z = _root;
				while (z->_color != NIL)
				{
					if (key_compare(value, z->_value))
						z = z->_left;
					else
						z = z->_right;
				}
				pointer	z_parent = z->_parent;
				*z = value_type(value);
				z->_parent = z_parent;
			}

		private:
			pointer	_root;

			reference	leftmost()
			{
				pointer	z = _root;

				if (z->_color == NIL)
					return *z;
				while (z->_left->_color != NIL)
					z = z->_left;
				return *z;
			}

			reference	rightmost()
			{
				pointer	z = _root;

				if (z->_color == NIL)
					return *z;
				while (z->_right->_color != NIL)
					z = z->_right;
				return *z;
			}
	};
};

#endif
