/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:28:26 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:28:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_bzero" sets the first n bytes of the memory area pointed to 
 * by s to zero.
 * It is typically used to initialize a memory block to zero.
 * 
 * @param s 			A pointer to the memory area to be zeroed.
 * @param n 			The number of bytes to be set to zero.
 * 
 * @return None. 		The function modifies the memory area directly. 
 * 
 */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;	

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
