/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:28:09 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:28:09 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_atoi" converts a string to an integer.
 * It handles leading whitespaces, optional '+' or '-' signs, and numerical 
 * digits. If the string starts with a valid number representation, the 
 * function returns its integer equivalent.
 * 
 * @param str 		The input string to be converted into an integer.
 *            		It can include leading whitespaces and an optional '+' or 
 * 					'-' sign before the numerical digits.
 * 
 * @return 			The converted integer value of the input string, taking 
 * 					into account the sign. Returns 0 if no valid number is 
 * 					found.
 * 
 */

int	ft_atoi(const char *str)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		sign = (44 - (*str++));
	while (*str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	return (n * sign);
}
