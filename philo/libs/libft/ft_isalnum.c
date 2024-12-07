/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:28:54 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:28:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_isalnum" checks if the given character is alphanumeric. A 
 * character is considered alphanumeric if it is a letter (uppercase or 
 * lowercase) or a digit.
 * 
 * @param c 				The character to be checked, represented as an 
 * 							integer. It can be the ASCII value of the 
 * 							character.
 * 
 * @return 1 				if the character is alphanumeric (letter or digit),
 * 							otherwise 0.
 * 
 */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
