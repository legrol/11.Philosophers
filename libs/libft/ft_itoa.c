/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:58:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/24 13:58:52 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * The function "ft_itoa" converts an integer to its string representation.
 * It handles positive and negative integers and returns the string 
 * representation of the integer, allocating memory dynamically.
 * 
 * @param n 			The integer to be converted into a string.
 * 
 * @return 				A dynamically allocated string representing the 
 * 						integer. Returns NULL if the memory allocation fails.
 * 
 * The function "count_chr" calculates the number of characters needed to 
 * represent an integer in string form, including the sign if the number is 
 * negative.
 * 
 * @param n 			The integer whose character count is to be determined.
 * 
 * @return 				The number of characters required to represent the 
 * 						integer as a string, including the null-terminator.
 * 
 */

static unsigned int	count_chr(int n)
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

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	totalchr;
	unsigned int	number;

	totalchr = count_chr(n);
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
