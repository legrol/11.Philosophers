/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:29:09 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:29:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_isalpha" checks if the given character is an alphabetic 
 * character. A character is considered alphabetic if it is a letter 
 * (uppercase or lowercase).
 * 
 * @param c 			The character to be checked, represented as an integer.
 *          			It can be the ASCII value of the character.
 * 
 * @return 1 			if the character is alphabetic (uppercase or 
 * 						lowercase), otherwise 0.
 * 
 */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
