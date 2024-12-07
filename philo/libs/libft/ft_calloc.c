/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:28:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:28:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_calloc" allocates memory for an array of count elements, 
 * each of size bytes, and initializes all bytes in the allocated memory to 
 * zero.
 * It combines the functionality of malloc and memset/ft_bzero.
 * 
 * @param count 			The number of elements to allocate.
 * @param size 				The size of each element in bytes.
 * 
 * @return 					A pointer to the allocated memory initialized to 
 * 							zero, or NULL if the allocation fails.
 * 
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *) malloc(count * size);
	if (ptr == NULL)
		return (0);
	else
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
}
