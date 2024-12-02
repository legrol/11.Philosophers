/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:19:36 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strncmp" compares up to n characters of two strings. The 
 * comparison is based on the ASCII values of the characters and stops when a 
 * difference is found, n characters are compared, or a null-terminator is 
 * encountered.
 * 
 * @param s1 				The first string to be compared.
 * @param s2 				The second string to be compared.
 * @param n 				The maximum number of characters to compare.
 * 
 * @return 					An integer greater than, equal to, or less than 0,
 * 							depending on whether the first string is greater 
 * 							than, equal to, or less than the second string.
 * 
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else if ((unsigned char) s1[i] < (unsigned char) s2[i])
			return (-1);
		else
			i++;
	}
	return (0);
}
