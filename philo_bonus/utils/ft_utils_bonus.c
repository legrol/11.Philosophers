/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:12:19 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/18 19:09:51 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_strcmp" compares two strings lexicographically. It returns 
 * the difference between the first unmatched characters in the two strings 
 * or zero if the strings are identical.
 * 
 * @param const char *s1			The first string to be compared.
 * @param const char *s2			The second string to be compared.
 * 
 * @return int						Returns an integer less than, equal to, or 
 * 									greater than zero if `s1` is found, 
 * 									respectively, to be less than, to match, 
 * 									or to be greater than `s2`.
 * 
 * The function "ft_philo_atoi" converts a string representation of an integer 
 * into its integer equivalent. It handles leading whitespaces, an optional 
 * '+' or '-' sign, and numerical digits. If the string starts with a valid 
 * number representation, the function returns its integer equivalent.
 * 
 * @param const char *str			The input string to be converted into 
 * 									an integer.
 * 
 * @return int						Returns the converted integer value. If 
 * 									the string does not start with a valid 
 * 									number, the behavior is undefined.
 * 
 */

int	ft_philo_atoi(const char *str)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
