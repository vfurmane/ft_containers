/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:20:44 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/28 22:29:56 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

namespace ft
{
	class _rb_tree
	{
		public:
			_rb_tree(void)
			{
			}
			_rb_tree(const _rb_tree &obj)
			{
				*this = obj;
			}
			~_rb_tree(void)
			{
			}

			_rb_tree	&operator=(const _rb_tree &rhs)
			{
				(void)rhs;
				return *this;
			}
	};
};

#endif
