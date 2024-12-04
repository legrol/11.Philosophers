/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:20:34 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/04 13:41:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * The function "ft_putchar" writes a single character to the standard output.
 * 
 * @param char c    		The character to write.
 * 
 * @return 					The number of characters written (always 1).
 * 
 */

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
