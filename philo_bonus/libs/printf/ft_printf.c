/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 07:42:38 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/04 13:42:21 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/**
 * The function "ft_printf" is a formatted output conversion function.
 * It processes a format string and prints the corresponding arguments.
 * 	
 * @param char const *str    	The format string containing text and 
 * 								specifiers.
 * @param ...                	The variadic arguments to format and print.
 * 
 * @return 						The total number of characters printed.
 * 
 * The function "ft_checker" processes a format specifier and calls the 
 * appropriate function to handle the corresponding argument.
 * 
 * @param va_list args      	The list of arguments passed to the function.
 * @param char checker      	The format specifier to check and process.
 * 
 * @return 						If all goes well: the number of characters 
 * 								printed.
 *								On failure or if the specifier is invalid: -1.
 * 
 */

static int	ft_checker(va_list args, char checker)
{
	int	print_len;

	print_len = 0;
	if (checker == 'c')
		print_len += ft_putchar((char)va_arg(args, int));
	else if (checker == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (checker == 'p')
		print_len += ft_putptr(va_arg(args, uintptr_t));
	else if (checker == 'd')
		print_len += ft_putnbr(va_arg(args, int));
	else if (checker == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	else if (checker == 'u')
		print_len += ft_putnbr_uns(va_arg(args, unsigned int));
	else if (checker == 'x')
		print_len += ft_puthex(va_arg(args, unsigned int), checker);
	else if (checker == 'X')
		print_len += ft_puthex(va_arg(args, unsigned int), checker);
	else if (checker == '%')
		print_len += ft_putchar('%');
	else
		return (-1);
	return (print_len);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%' && str[i] != '\0')
			count += ft_putchar(str[i]);
		if (str[i] == '%')
		{
			i++;
			count += ft_checker(args, str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
