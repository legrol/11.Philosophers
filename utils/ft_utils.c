/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-05 10:41:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-12-05 10:41:10 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_isint" checks whether a given string represents a valid 
 * integer within the range of `INT_MIN` and `INT_MAX`.
 * 
 * @param char *nbr    The string to check.
 * 
 * @return             1 if the string represents a valid integer.
 *                     0 otherwise.
 * 
 */

int	ft_isint(char *nbr)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	result = ft_atoi(nbr);
	if (result <= INT_MAX || result >= INT_MIN)
		return (1);
	else
		return (0);
}
