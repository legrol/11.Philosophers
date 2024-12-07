/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:26:37 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/04 13:47:06 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * The function "ft_putptr" writes a pointer's memory address to the 
 * standard output in hexadecimal format, prefixed with "0x".
 * 
 * @param uintptr_t ptr				The pointer to write.
 * 
 * @return							The number of characters written.
 * 
 */

int	ft_putptr(uintptr_t	ptr)
{
	size_t	count;

	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(ptr, 'x');
	return (count);
}
