/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:04:51 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:04:51 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_memset" fills the first n bytes of the memory area pointed 
 * to by s with the specified byte value c.
 * 
 * @param s 				A pointer to the memory area to be filled.
 * @param c 				The byte value to fill the memory area with, 
 * 							converted to an unsigned char.
 * @param n 				The number of bytes to fill in the memory area.
 * 
 * @return 					A pointer to the memory area s.
 * 
 */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
