/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:32:35 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/07 17:49:49 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

/**
 * The function "ft_strjoin2" concatenates two strings into a newly allocated 
 * buffer and null-terminates the result.
 * 
 * @param char const *s1				The first string.
 * @param char const *s2				The second string.
 * 
 * @return								If all goes well: a pointer to the 
 * 										newly allocated string.
 *										On failure: NULL.
 * 
 * The function "ft_strlcpy2" copies up to size - 1 characters from the source 
 * string to the destination string, null-terminating the result if size is 
 * not 0.
 * 
 * @param char *dest					The destination buffer.
 * @param const char *src				The source string.
 * @param size_t size					The size of the destination buffer.
 * 
 * @return								The total length of the source string.
 * 
 * The function "ft_strdup2" allocates memory and duplicates the given string.
 * 
 * @param const char *s					The string to duplicate.
 * 
 * @return								If all goes well: a pointer to the 
 * 										newly allocated string.
 *										On failure: NULL.
 *  
 * The function "ft_strlen2" calculates the length of a string.
 * 
 * @param const char *s					The string whose length is to be 
 * 										calculated.
 * 
 * @return								The length of the string. 
 * 
 */

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen2(s);
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

size_t	ft_strlcpy2(char *dest, const char *src, size_t size)
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

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*str3;
	int		totallen;
	int		i;
	int		j;

	totallen = ft_strlen2(s1) + ft_strlen2(s2);
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

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen2(s))
		return (ft_strdup2(""));
	if (len > ft_strlen2(s + start))
		len = ft_strlen2(s + start);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy2(str, (s + start), len + 1);
	return (str);
}
