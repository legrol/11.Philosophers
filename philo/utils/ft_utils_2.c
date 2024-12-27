/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:46:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 13:18:16 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_sleep" implements a custom sleep mechanism, allowing the 
 * program to pause execution for a specified amount of time in milliseconds. 
 * It continuously checks whether the stopping condition in the environment 
 * (`stopping_rule`) has been triggered, ensuring that the sleep can be 
 * interrupted if necessary.
 * 
 * @param unsigned long total_time	The duration to sleep in milliseconds.
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that contains the stopping rule and other 
 * 									simulation parameters.
 * 
 * The function "ft_get_time" retrieves the current time in milliseconds since 
 * the Unix epoch (January 1, 1970). It uses the `gettimeofday` function to 
 * obtain the time in seconds and microseconds and converts it to milliseconds.
 * 
 * @return unsigned long			Returns the current time in milliseconds.
 * 
 * The function "ft_isinteger" checks whether a given string represents a valid 
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
	result = ft_philo_atoi(nbr);
	if (result >= INT_MIN && result <= INT_MAX)
		return (1);
	return (0);
}

unsigned long	ft_get_time(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, NULL);
	return ((mytime.tv_sec * (unsigned long)1000) + (mytime.tv_usec / 1000));
}
