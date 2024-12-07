/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:17:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:17:59 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strdup" duplicates a given string by allocating sufficient 
 * memory for a new copy of the string and copying its content into the newly 
 * allocated space.
 * 
 * @param s 				The input string to be duplicated.
 * 
 * @return 					A pointer to the newly allocated copy of the 
 * 							string. 
 *							Returns NULL if the memory allocation fails.
 * 
 */

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s);
	str = (char *) malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
