/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strlcpy" copies up to size - 1 characters from the string 
 * "src" to "dest", null-terminating the result if size is not 0. It is 
 * designed to prevent buffer overflows.
 * 
 * @param dest 				The destination buffer where the string will be 
 * 							copied.
 * @param src 				The source string to be copied.
 * @param size 				The size of the destination buffer, including space
 * 							for the null-terminator.
 * 
 * @return 					The total length of the string in "src", regardless
 * 							of how many characters were actually copied.
 * 
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size < 1)
		return (count);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}
