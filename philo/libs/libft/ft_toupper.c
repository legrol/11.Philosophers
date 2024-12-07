/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:20:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:20:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_toupper" converts a lowercase letter to its corresponding
 * uppercase letter. If the input character is not a lowercase letter, it is 
 * returned unchanged.
 * 
 * @param c 					The character to be converted, represented as 
 * 								an integer.
 * 
 * @return 						The uppercase equivalent of the character if it 
 * 								is a lowercase letter; otherwise, the character
 * 								is returned unchanged.
 * 
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
