/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:17:44 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:17:44 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strchr" locates the first occurrence of a character in a 
 * string and returns a pointer to the matched character. If the character is 
 * '\0', the function returns a pointer to the null terminator.
 * 
 * @param s 				The input string to be searched.
 * @param c 				The character to locate in the string. It is 
 * 							treated as an unsigned char cast to an int.
 * 
 * @return 					A pointer to the first occurrence of the specified
 * 							character in the string. If the character is '\0',
 * 							the function returns a pointer to the null 
 * 							terminator. If the character is not found, the
 * 							function returns NULL.
 * 
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		else
			s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (0);
}