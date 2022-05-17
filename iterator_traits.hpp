/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:29:25 by vfurmane          #+#    #+#             */
/*   Updated: 2022/05/17 11:34:40 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "iterator_tag.hpp"

namespace ft
{
	template <class Iter>
	class iterator_traits
	{
		public:
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
			typedef typename Iter::iterator_category	iterator_category;
	};
	template <class T>
	class iterator_traits<T *>
	{
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};
	template <class T>
	class iterator_traits<const T *>
	{
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef const T *						pointer;
			typedef const T &						reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};
};

#endif
