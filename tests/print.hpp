/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:58:12 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/27 17:24:34 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

# include <iostream>

template <class Iterator>
void print_container_iter(Iterator begin, Iterator end)
{
	std::cout << " { ";
	while (begin != end)
	{
		std::cout << *begin << (begin < end - 1 ? ", " : "");
		begin++;
	}
	std::cout << " }" << std::endl;
}

template <typename T1, typename T2>
std::ostream	&operator<<(std::ostream &os, const NAMESPACE::pair<T1, T2> rhs)
{
	os << "(" << rhs.first << ", " << rhs.second << ")";
	return os;
}

#endif
