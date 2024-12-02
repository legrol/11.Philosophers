/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:20:27 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:20:27 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_substr" creates a new substring from a given string, 
 * starting at a specified position and having a maximum length of "len".
 * If the start position is greater than the length of the string, the function
 * returns an empty string.
 * 
 * @param s 					The input string from which the substring will 
 * 								be created.
 * @param start 				The starting index of the substring in the 
 * 								string.
 * @param len 					The maximum length of the substring.
 * 
 * @return 						A pointer to the newly allocated substring. 
 * 								Returns NULL if memory allocation fails or if 
 * 								the input string is NULL.
 * 
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
