/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair().cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:27:05 by vfurmane          #+#    #+#             */
/*   Updated: 2022/06/25 19:17:11 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef USE_STD
# include <utility>
#else
# include "utility.hpp"
#endif

int	main(void)
{
	NAMESPACE::pair<int, float>	obj;
	(void)obj;
}
