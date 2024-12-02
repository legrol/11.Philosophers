/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:50:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:50:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_isdigit" checks if the given character is a digit. A 
 * character is considered a digit if it is between '0' and '9' in the ASCII 
 * table.
 * 
 * @param c 			The character to be checked, represented as an integer.
 *          			It can be the ASCII value of the character.
 * 
 * @return 1 			if the character is a digit (value between '0' and 
 * 						'9'), otherwise 0.
 * 
 */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
