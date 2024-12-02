/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:18:26 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:09 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_striteri" iterates through a string, applying a given 
 * function to each character of the string. The function receives the 
 * character's index and a pointer to the character as arguments.
 * 
 * @param s 			The input string to be iterated. If the string is NULL, 
 *						the function does nothing.
 * @param f 			A function pointer to the function to be applied to 
 * 						each character of the string. The function takes the 
 * 						index of the character and a pointer to the character 
 * 						as arguments.
 * 
 * @return None. 		The function performs the operation directly on the 
 * 						string.
 * 
 */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
