/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:05:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:05:28 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_putendl_fd" writes a string followed by a newline character
 * to the specified file descriptor.
 * 
 * @param s 				The string to be written. If the string is NULL, 
 * 							the function does nothing.
 * @param fd 				The file descriptor to which the string and newline 
 * 							character will be written. Common values are 0 for 
 * 							standard input, 1 for standard output, and 2 for 
 * 							standard error.
 * 
 * @return None. 			The function performs the operation directly and 
 * 							does not return a value.
 * 
 */

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
