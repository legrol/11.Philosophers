/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:41:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/08 21:49:33 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_philo_itoa" converts an integer to its string 
 * representation.
 * It handles positive and negative integers and returns the string 
 * representation of the integer, allocating memory dynamically.
 * 
 * @param n 			The integer to be converted into a string.
 * 
 * @return 				A dynamically allocated string representing the 
 * 						integer. Returns NULL if the memory allocation fails.
 * 
 * The function "philo_count_chr" calculates the number of characters needed to 
 * represent an integer in string form, including the sign if the number is 
 * negative.
 * 
 * @param n 			The integer whose character count is to be determined.
 * 
 * @return 				The number of characters required to represent the 
 * 						integer as a string, including the null-terminator.
 * 
 * The function "ft_philo_atoi" converts a string to an integer.
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
 * The function "ft_isint" checks whether a given string represents a valid 
 * integer within the range of `INT_MIN` and `INT_MAX`.
 * 
 * @param char *nbr    The string to check.
 * 
 * @return             1 if the string represents a valid integer.
 *                     0 otherwise.
 * 
 */

int	ft_isinteger(char *nbr)
{
	long	result;

	result = 0;
	result = ft_atoi(nbr);
	if (result <= INT_MAX || result >= INT_MIN)
		return (1);
	else
		return (0);
}

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

static unsigned int	philo_count_chr(int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_philo_itoa(int n)
{
	char			*str;
	unsigned int	totalchr;
	unsigned int	number;

	totalchr = philo_count_chr(n);
	str = (char *) malloc((totalchr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		str[0] = '0';
	str[totalchr] = '\0';
	while (number != 0)
	{
		str[totalchr -1] = (number % 10) + '0';
		number = number / 10;
		totalchr--;
	}
	return (str);
}
