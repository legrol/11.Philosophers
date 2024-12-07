/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:04:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:04:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_memcmp" compares the first n bytes of two memory areas.
 * It determines whether they are identical or which one is greater based on 
 * their byte values.
 * 
 * @param s1 					A pointer to the first memory area.
 * @param s2 					A pointer to the second memory area.
 * @param n 					The number of bytes to compare.
 * 
 * @return 						An integer less than, equal to, or greater than
 * 								0, depending on whether the first memory area 
 * 								is less than, equal to, or greater than the 
 * 								second memory area. If n is 0, the function 
 * 								returns 0.
 * 
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;
	size_t				i;

	i = 0;
	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (i < n)
	{
		if (*str1 != *str2)
			return ((int)(*str1 - *str2));
		str1++;
		str2++;
		i++;
	}
	return (0);
}
