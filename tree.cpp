/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:43:46 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/30 15:17:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "tree.hpp"

template <class T>
std::ostream	&operator<<(std::ostream &os, const ft::_rb_tree_node<T> &obj)
{
	if (obj._left->_color != ft::NIL)
		os << obj._left->_value;
	else
		os << "nil";
	os << " <-- ";
	os << obj._value;
	os << " (" << (obj._color ? "BLACK" : "RED") << ")";
	os << " --> ";
	if (obj._right->_color != ft::NIL)
		os << obj._right->_value;
	else
		os << "nil";
	return os;
}

int	main(void)
{
	ft::_rb_tree<int>	obj;
	obj.insert(42);
	obj.insert(47);
	obj.insert(0);
	obj.insert(1337);
	for (auto it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
