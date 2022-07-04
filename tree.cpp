/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:43:46 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/04 14:36:57 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include "tree.hpp"

template<typename T>
std::ostream	&operator<<(std::ostream &os, const ft::rb_tree_node<T> &rhs)
{
	if (rhs.left != NULL)
		os << rhs.left->value;
	else
		os << "nil";
	os << " <-- ";
	os << rhs.value;
	// os << " (" << (rhs._color ? "BLACK" : "RED") << ")";
	os << " --> ";
	if (rhs.right != NULL)
		os << rhs.right->value;
	else
		os << "nil";
	return os;
}

int	main(void)
{
	ft::rb_tree< int, std::less<int> >	obj;
	obj.insert(42);
	obj.insert(47);
	obj.insert(7);
	obj.insert(21);
	obj.insert(0);
	obj.insert(1337);
	obj.insert(54);
	obj.insert(36);
	for (auto it = obj.begin(); it != obj.end(); ++it)
		std::cout << *it << std::endl;
}
