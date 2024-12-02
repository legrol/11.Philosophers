/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:19:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:19:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strnstr" locates the first occurrence of the substring 
 * "to_find" in the string "str", searching only up to n characters. If the 
 * substring is found, the function returns a pointer to the beginning of 
 * the located substring within "str".
 * 
 * @param str 					The string to be searched.
 * @param to_find 				The substring to locate in "str".
 * @param n 					The maximum number of characters to search in 
 * 								"str".
 * 
 * @return 						A pointer to the beginning of the located 
 * 								substring in "str". 
 *								Returns NULL if the substring is not found or 
 * 								if "to_find" is NULL.
 *								If "to_find" is an empty string, the function 
 * 								returns "str".
 * 
 */

char	*ft_strnstr(const char *str,	const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*to_find == '\0' || to_find == NULL)
		return ((char *)str);
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}
