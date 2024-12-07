/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:29:45 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:29:45 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_isascii" checks if the given character is part of the ASCII 
 * character set. The ASCII character set includes values from 0 to 127.
 * 
 * @param c 			The character to be checked, represented as an integer.
 *          			It can be the ASCII value of the character.
 * 
 * @return 1 			if the character is part of the ASCII character set 
 * 						(value between 0 and 127), otherwise 0.
 * 
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
