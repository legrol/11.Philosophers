/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:05:42 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:05:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_putnbr_fd" writes an integer to the specified file 
 * descriptor.
 * It handles negative numbers, the minimum integer value, and recursion for 
 * multi-digit numbers.
 * 
 * @param n 				The integer to be written.
 * @param fd 				The file descriptor to which the integer will be 
 * 							written. 
 *           				Common values are 0 for standard input, 1 for 
 * 							standard output, and 2 for standard error.
 * 
 * @return None. 			The function performs the operation directly and 
 * 							does not return a value.
 * 
 */

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		digit = (n + 48);
		write(fd, &digit, 1);
	}
}
