/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:04:42 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:04:42 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_memmove" copies n bytes from the source memory area to the 
 * destination memory area. It handles overlapping memory areas safely by 
 * copying the bytes in the correct order.
 * 
 * @param dest 			A pointer to the destination memory area where the 
 * 						bytes will be copied.
 * @param src 			A pointer to the source memory area from which the 
 * 						bytes will be copied.
 * @param n 			The number of bytes to copy from the source to the 
 * 						destination.
 * 
 * @return 				A pointer to the destination memory area. 
 * 						Returns dest even if the memory areas overlap or if n
 * 						is 0.
 * 
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			len;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	len = n;
	if ((!d && !s) || len <= 0)
		return (dest);
	if (s < d)
	{
		s = s + (len - 1);
		d = d + (len - 1);
		while (len-- > 0)
			*d-- = *s--;
		return (dest);
	}
	while (len-- > 0)
		*d++ = *s++;
	return (dest);
}
