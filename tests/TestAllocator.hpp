/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestAllocator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:03:01 by vfurmane          #+#    #+#             */
/*   Updated: 2022/07/07 12:32:43 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ALLOCATOR_HPP
# define TEST_ALLOCATOR_HPP

# include <iostream>
# include <memory>

template<class T>
struct TestAllocator : public std::allocator<T>
{
	typedef typename std::allocator<T>::size_type size_type;
	typedef typename std::allocator<T>::pointer pointer;

	TestAllocator() throw() : std::allocator<T>()
	{
		std::cout << "TestAllocator::TestAllocator has been called" << std::endl;
	}
	TestAllocator(const std::allocator<T>& other) throw() : std::allocator<T>(other)
	{
	}
	template<class U>
	TestAllocator(const std::allocator<U>& other) throw() : std::allocator<T>(other)
	{
	}

	virtual pointer allocate(size_type n, const void * hint = 0)
	{
		return std::allocator<T>::allocate(n, hint);
	}

	virtual size_type	max_size() const
	{
		std::cout << "TestAllocator::max_size has been called" << std::endl;
		return 42;
	}
};

#endif
