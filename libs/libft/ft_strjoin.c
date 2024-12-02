/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:28 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:28 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strjoin" concatenates two strings into a newly allocated 
 * string. The resulting string contains the content of the first string 
 * followed by the content of the second string.
 * 
 * @param s1 				The first input string.
 * @param s2 				The second input string.
 * 
 * @return 					A pointer to the newly allocated string containing 
 * 							the concatenated result. Returns NULL if memory 
 * 							allocation fails.
 * 
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str3;
	int		totallen;
	int		i;
	int		j;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	str3 = (char *) malloc((totallen + 1) * sizeof(char));
	if (!str3)
		return (0);
	while (s1[i] != '\0')
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str3[i] = s2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}