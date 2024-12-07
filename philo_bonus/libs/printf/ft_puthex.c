/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:23:39 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/04 13:43:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * The function "ft_puthex" converts an unsigned long long number to 
 * hexadecimal representation and writes it to the standard output.
 * 
 * @param unsigned long long nb    		The number to convert and print.
 * @param char checker             		Determines the case of the hexadecimal 
 *										output ('x' for lowercase, 'X' for 
 *										uppercase).
 * 
 * @return                          	The number of characters written.
 * 
 */

int	ft_puthex(unsigned long long nb, char checker)
{
	unsigned long long	count;

	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, checker);
	if (checker == 'x')
		ft_putchar("0123456789abcdef"[nb % 16]);
	if (checker == 'X')
		ft_putchar("0123456789ABCDEF"[nb % 16]);
	count++;
	return (count);
}
