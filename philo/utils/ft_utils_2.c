/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:46:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 21:42:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_clean_resources" cleans up all dynamically allocated 
 * resources and mutexes associated with the simulation environment. It ensures 
 * that all memory and synchronization primitives are properly released to 
 * avoid memory leaks or resource contention.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing allocated resources 
 * 									and mutexes.
 * 
 * @return void
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
	return ((mytime.tv_sec * (unsigned long)MS_CONVERSION) + \
	(mytime.tv_usec / MS_CONVERSION));
}

void	ft_clean_resources(t_envp *envp)
{
	int	i;

	ft_destroy_all_mutexes(envp);
	if (envp->philos)
	{
		i = 0;
		while (i < envp->nbr_philos)
		{
			if (envp->philos[i].pos_char)
				free(envp->philos[i].pos_char);
			i++;
		}
		free(envp->philos);
	}
	if (envp->forks)
		free(envp->forks);
}
