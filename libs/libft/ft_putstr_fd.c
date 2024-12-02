/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:18:20 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 14:05:55 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_putstr_fd" writes a string to the specified file 
 * descriptor.
 * 
 * @param s 				The string to be written. If the string is NULL,
 * 							the function does nothing.
 * @param fd 				The file descriptor to which the string will be 
 * 							written. 
 *							Common values are 0 for standard input, 1 for 
 *							standard output, and 2 for standard error.
 * 
 * @return None. 			The function performs the operation directly and 
 * 							does not return a value.
 * 
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
