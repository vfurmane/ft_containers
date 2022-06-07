/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value-wchar_t-11.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:20:52 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/02 11:58:13 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#ifndef USE_STD
# include "type_traits.hpp"
#endif

int	main(void)
{
	std::cout << "value <wchar_t> : ";
	std::cout << NAMESPACE::is_integral<wchar_t>::value << std::endl;
}
