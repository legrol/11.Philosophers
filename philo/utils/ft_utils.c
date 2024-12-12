/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:41:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/09 21:47:02 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_philo_itoa" converts an integer to its string 
 * representation. It dynamically allocates memory to store the string, 
 * handles both positive and negative integers, and reverses the string after 
 * construction.
 * 
 * @param int n 					The integer to be converted into a string.
 * 
 * @return char* 					A dynamically allocated string 
 * 									representing the integer. Returns NULL if 
 * 									the memory allocation fails.
 * 
 * The function "philo_count_chr" calculates the number of characters required 
 * to represent an integer as a string, including the sign for negative 
 * numbers and the null-terminator.
 * 
 * @param int n 					The integer whose character count is to 
 * 									be determined.
 * 
 * @return unsigned int				The number of characters needed to 
 * 									represent the integer as a string.
 * 
 * The function "ft_rev_str" reverses a string in place. It swaps the 
 * characters from the start and end of the string until the middle is reached.
 * 
 * @param char *str					A pointer to the string to be reversed.
 * 
 * @return void
 * 
 * The function "ft_strlen" calculates the length of a string by counting the 
 * number of characters until the null-terminator.
 * 
 * @param char *str					A pointer to the string whose length is to 
 * 									be calculated.
 * 
 * @return int						The length of the string, excluding the 
 * 									null-terminator.
 *  
 * The function "ft_philo_atoi" converts a string to its integer equivalent. 
 * It handles leading whitespaces, an optional '+' or '-' sign, and numerical 
 * digits. If no valid number is found at the beginning of the string, the 
 * function returns 0.
 * 
 * @param const char *str			The input string to be converted into an 
 * 									integer.
 * 
 * @return int						The converted integer value of the input 
 * 									string, taking into account the sign. 
 * 									Returns 0 if no valid number is found.
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

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_rev_str(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
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
	int				i;
	unsigned int	number;

	i = 0;
	str = malloc((philo_count_chr(n) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	if (n < 0)
		number = -1 * n;
	else
		number = n;
	while (number != 0)
	{
		str[i++] = (number % 10) + '0';
		number /= 10;
	}
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_rev_str(str);
	return (str);
}
