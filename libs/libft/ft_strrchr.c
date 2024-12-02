/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:20:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:20:07 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strrchr" locates the last occurrence of a character in a
 * string and returns a pointer to it. If the character is '\0', the function 
 * returns a pointer to the null terminator.
 * 
 * @param s 					The input string to be searched.
 * @param c 					The character to locate in the string. It is 
 * 								treated as an unsigned char cast to an int.
 * 
 * @return 						A pointer to the last occurrence of the 
 * 								specified character in the string. If the 
 * 								character is '\0', the function returns a
 * 								pointer to the null terminator. If the 
 * 								character is not found, the function returns 
 * 								NULL.
 * 
 */

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			last = (char *) s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (last);
}
