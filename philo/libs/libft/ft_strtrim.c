/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:49:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:20:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strtrim" removes all characters from the beginning and end
 * of a string that are present in a specified set of characters. The result is
 * a newly allocated trimmed string.
 * 
 * @param s1 				The input string to be trimmed.
 * @param set 				The set of characters to be trimmed from the 
 * 							beginning and end of the string.
 * 
 * @return 					A pointer to the newly allocated trimmed string. 
 *							Returns NULL if memory allocation fails or if the 
 *							input string or set is NULL.
 * 
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	first = 0;
	if (!s1 || !set)
		return (NULL);
	while (*(s1 + first) && ft_strchr(set, *(s1 + first)))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_strchr(set, *(s1 + (last - 1))))
		last--;
	return (ft_substr(s1, first, (last - first)));
}
