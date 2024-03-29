/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 09:49:43 by vfurmane          #+#    #+#             */
/*   Updated: 2022/08/03 20:54:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_tag.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator : public iterator<typename ft::iterator_traits<Iterator>::iterator_category, Iterator>
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			reverse_iterator(void) : _iterator(NULL)
			{
			}
			~reverse_iterator(void)
			{
			}
			explicit reverse_iterator(iterator_type it) : _iterator(it)
			{
			}
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : _iterator(rev_it.base())
			{
			}

			iterator_type base() const
			{
				return _iterator;
			}
			reference operator*() const
			{
				Iterator tmp = _iterator;
				return *(--tmp);
			}
			reverse_iterator	operator+(difference_type n) const
			{
				return reverse_iterator(base() - n);
			}
			reverse_iterator	&operator++()
			{
				--_iterator;
				return *this;
			}
			reverse_iterator	operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			reverse_iterator	&operator+=(difference_type n)
			{
				_iterator -= n;
				return *this;
			}
			reverse_iterator	operator-(difference_type n) const
			{
				return reverse_iterator(base() + n);
			}
			reverse_iterator	&operator--()
			{
				++_iterator;
				return *this;
			}
			reverse_iterator	operator--(int)
			{
				reverse_iterator temp = *this;
				--(*this);
				return temp;
			}
			reverse_iterator	&operator-=(difference_type n)
			{
				_iterator += n;
				return *this;
			}
			pointer	operator->() const
			{
				iterator_type	tmp = base();
				return &(*--tmp);
			}
			reference	operator[](difference_type n) const
			{
				return base()[-n - 1];
			}


		private:
			iterator_type	_iterator;
	};

	template <class lit, class rit>
	bool	operator==(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return lhs.base() == rhs.base();
	}
	template <class lit, class rit>
	bool	operator!=(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return lhs.base() != rhs.base();
	}
	template <class lit, class rit>
	bool	operator<(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return lhs.base() > rhs.base();
	}
template <class lit, class rit>
	bool	operator<=(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	template <class lit, class rit>
	bool	operator>(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	template <class lit, class rit>
	bool	operator>=(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return rev_it + n;
	}

	template <class lit, class rit>
	typename reverse_iterator<lit>::difference_type	operator-(const reverse_iterator<lit>& lhs, const reverse_iterator<rit>& rhs)
	{
		return rhs.base() - lhs.base();
	}
};

#endif
