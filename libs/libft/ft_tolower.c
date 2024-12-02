/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:20:40 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:20:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_tolower" converts an uppercase letter to its corresponding 
 * lowercase letter. If the input character is not an uppercase letter, it is 
 * returned unchanged.
 * 
 * @param c 					The character to be converted, represented as 
 * 								an integer.
 * 
 * @return 						The lowercase equivalent of the character if it
 * 								is an uppercase letter; otherwise, the 
 * 								character is returned unchanged.
 * 
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
