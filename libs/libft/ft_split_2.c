/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-02 09:07:22 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-12-02 09:07:22 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_split_r" splits a string into substrings based on a given 
 * delimiter character. Each substring is allocated dynamically and stored in 
 * an array of strings.
 * 
 * @param s 				The input string to be split.
 * @param c 				The delimiter character used to split the string.
 * 
 * @return 					A pointer to an array of strings containing the 
 * 							split substrings. 
 *							Returns NULL if memory allocation fails.
 * 
 * The function "fillsplit_r" fills an array of strings with substrings 
 * extracted from the input string, splitting at each occurrence of the 
 * delimiter character.
 * 
 * @param ssplit 			The array of strings to be filled.
 * @param s 				The input string to be split.
 * @param c 				The delimiter character used to split the string.
 * 
 * @return 					The filled array of strings. Returns NULL if memory 
 * 							allocation fails.
 * 
 * The function "freessplit_r" frees all allocated memory for the split result
 * in case of an error during the splitting process.
 * 
 * @param ssplit 			The array of strings to be freed.
 * @param k 				The index of the last successfully allocated string 
 * 							in the array.
 * 
 * @return NULL. 			The function always returns NULL after freeing the 
 * 							memory.
 * 
 * The function "mallocsize_r" calculates the number of substrings separated by
 * a given character in the input string. This value is used to determine the 
 * memory allocation size for the split result.
 * 
 * @param s 				The input string to be split.
 * @param c 				The delimiter character used to split the string.
 * 
 * @return 					The number of substrings in the input string.
 * 
 */

static unsigned int	mallocsize_r(char const *s, char c)
{
	int	ms;
	int	i;

	i = 0;
	ms = 0;
	if (s[0] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			ms++;
		i++;
	}
	if (s[i - 1] != c)
		ms++;
	return (ms);
}

static void	*freessplit_r(char **ssplit, int k)
{
	while (k >= 0)
	{
		free(ssplit[k]);
		k--;
	}
	free(ssplit);
	return (NULL);
}

static char	**fillsplit_r(char **ssplit, char const *s, char c)
{
	size_t	i;
	int		j;
	size_t	k;

	i = 0;
	k = 0;
	j = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && j == -1)
			j = i;
		else if ((s[i] == c || i == ft_strlen(s)) && j != -1)
		{
			ssplit[k] = ft_substr(s, j, i - j);
			if (!ssplit[k])
				if (freessplit_r(ssplit, k) == NULL)
					return (NULL);
			k++;
			j = -1;
		}
		i++;
	}
	ssplit[k] = NULL;
	return (ssplit);
}

char	**ft_split_r(char const *s, char c)
{
	char	**ssplit;

	ssplit = (char **)malloc((mallocsize_r(s, c) + 1) * sizeof(char *));
	if (!ssplit)
		return (NULL);
	ssplit = fillsplit_r(ssplit, s, c);
	if (!ssplit)
		return (freessplit_r(ssplit, mallocsize_r(s, c)));
	return (ssplit);
}
