/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:03:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:03:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_memchr" searches for the first occurrence of a specified 
 * byte (converted from an integer) in the first n bytes  of a memory area.
 * 
 * @param s 				A pointer to the memory area to be searched.
 * @param c 				The byte value to search for, interpreted as an 
 * 							unsigned char.
 * @param n 				The number of bytes to search in the memory area.
 * 
 * @return 					A pointer to the first occurrence of the byte in 
 * 							the memory area. 
 *							Returns NULL if the byte is not found within the 
 *							first n bytes.
 * 
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;
	char	l;

	str = (char *)s;
	l = (char)c;
	i = 0;
	while (i < n)
	{
		if (*str == l)
			return (str);
		str++;
		i++;
	}
	return (0);
}
