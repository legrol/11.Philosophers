/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strlcat" appends the string "src" to the end of "dest", 
 * ensuring that the resulting string in "dest" is null-terminated and does not
 * exceed the given buffer size. The function is designed to prevent buffer 
 * overflows.
 * 
 * @param dest 				The destination string to which "src" will be 
 * 							appended.
 * @param src 				The source string to append to "dest".
 * @param size 				The total size of the buffer, including the space 
 * 							for the null-terminator.
 * 
 * @return 					The total length of the string it tried to create, 
 * 							which is the initial length of "dest" plus the 
 * 							length of "src".
 * 
 */

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dest[len] != '\0' && len < size)
		len++;
	i = len;
	while (src[len - i] != '\0' && len + 1 < size)
	{
		dest[len] = src[len - i];
		len++;
	}
	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}
