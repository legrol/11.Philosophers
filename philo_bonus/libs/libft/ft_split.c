/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:06:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:06:31 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_split" splits a string into an array of words based on a 
 * specified delimiter character. Each word is dynamically allocated.
 * 
 * @param s 				The input string to be split.
 * @param c 				The delimiter character used to separate words.
 * 
 * @return 					A pointer to an array of strings containing the 
 * 							split words. 
 *							Returns NULL if memory allocation fails or if the 
 *							input string is NULL.
 * 
 * The function "create_word" populates an array of strings with words 
 * extracted from the input string, splitting at each occurrence of the
 * delimiter character.
 * 
 * @param s 				The input string to be split.
 * @param c 				The delimiter character used to separate words.
 * @param str 				The array of strings to be populated.
 * @param words_count 		The total number of words in the string.
 * 
 * @return 					A pointer to the populated array of strings. 
 *							Returns NULL if memory allocation fails.
 * 
 * The function "free_str" frees all previously allocated strings in an array
 * of strings up to a specified index.
 * 
 * @param i 				The number of allocated strings to free.
 * @param str 				The array of strings to be freed.
 * 
 * @return None. 			The memory is released directly.
 * 
 * The function "count_word_len" calculates the length of the next word in a 
 * string starting at a specific position, stopping at the delimiter.
 * 
 * @param s 				A pointer to the start of the word in the string.
 * @param c 				The delimiter character that separates words.
 * 
 * @return 					The length of the word.
 * 
 * The function "count_words" counts the number of words in a string separated
 * by a specified delimiter character.
 * 
 * @param s 				The input string to be analyzed.
 * @param c 				The delimiter character used to separate words.
 * 
 * @return 					The total number of words in the string.
 * 
 */

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && (s[i] != c))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	count_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static void	free_str(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free (*(str + i));
	}
	free(str);
}

static char	**create_word(char const *s, char c, char **str, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(str + i) = ft_substr(s, j, count_word_len(&*(s + j), c));
		if (!*(str + i))
		{
			free_str(i, str);
			return (0);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(str + i) = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	totalwords;

	if (!s)
		return (NULL);
	totalwords = count_words(s, c);
	str = (char **) malloc((totalwords + 1) * (sizeof(char *)));
	if (!str)
		return (NULL);
	str = create_word(s, c, str, totalwords);
	return (str);
}
