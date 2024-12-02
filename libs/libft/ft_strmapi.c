/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:10:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:19:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_strmapi" applies a given function to each character of a 
 * string to create a new dynamically allocated string with the transformed 
 * characters.
 * 
 * @param s 				The input string to be transformed.
 * @param f 				A function pointer that takes the index of the 
 * 							character and the character itself as arguments, 
 * 							returning the transformed character.
 * 
 * @return 					A pointer to the newly allocated string containing 
 * 							the transformed characters. Returns NULL if the 
 * 							memory allocation fails or if the input string is 
 * 							NULL.
 *
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	int				totalchr;

	i = 0;
	if (!s)
		return (NULL);
	totalchr = ft_strlen(s);
	str = (char *) malloc((totalchr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
