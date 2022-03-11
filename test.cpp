/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:32:02 by vfurmane          #+#    #+#             */
/*   Updated: 2022/03/11 11:15:39 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Default value for the USE_STD macro
#ifndef USE_STD
# define USE_STD 0
#endif

// Select the namespace to use
#if USE_STD == 0
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

#include <iostream>

int	main(void)
{
	return 0;
}
