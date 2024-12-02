/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:58:26 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:58:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_isprint" checks if the given character is a printable 
 * character. Printable characters include all characters with ASCII values 
 * from 32 to 126 inclusive (including space).
 * 
 * @param c 			The character to be checked, represented as an integer.
 *          			It can be the ASCII value of the character.
 * 
 * @return 1 			if the character is printable (value between 32 and 
 * 						126), otherwise 0.
 * 
 */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}
