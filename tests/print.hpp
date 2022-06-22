/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:58:12 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/06 11:18:35 by vfurmane         ###   ########.fr       */
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

#endif
