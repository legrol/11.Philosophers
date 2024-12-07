/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:05:14 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:05:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_putchar_fd" writes a single character to the specified file
 * descriptor.
 * 
 * @param c 				The character to be written.
 * @param fd 				The file descriptor to which the character will be 
 * 							written. 
 *							Common values are 0 for standard input, 1 for 
 *							standard output, and 2 for standard error.
 * 
 * @return None. 			The function performs the operation directly and 
 * 							does not return a value.
 * 
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
