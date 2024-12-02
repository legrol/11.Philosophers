/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:04:22 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:04:22 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_memcpy" copies n bytes from the source memory area to the 
 * destination memory area. The memory areas should not overlap.
 * 
 * @param dest 			A pointer to the destination memory area where the 
 * 						bytes will be copied.
 * @param src 			A pointer to the source memory area from which the 
 * 						bytes will be copied.
 * @param n 			The number of bytes to copy from the source to the 
 * 						destination.
 * 
 * @return 				A pointer to the destination memory area.
 * 						Returns NULL if both dest and src are NULL.
 * 
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
