/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:46:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 22:50:22 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_safe_free" safely frees a dynamically allocated pointer and 
 * sets it to NULL to prevent dangling pointers. It ensures memory is properly 
 * released without causing double-free errors.
 * 
 * @param void **ptr				A double pointer to the memory to be freed. 
 * 									The pointer is set to NULL after the memory 
 * 									is freed.
 * 
 * @return void
 * 
 * The function "ft_clean_resources" performs a complete cleanup of all 
 * dynamically allocated resources and mutexes in the simulation environment. 
 * It ensures proper deallocation of memory and destroys all synchronization 
 * primitives to avoid memory leaks and resource contention.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing all allocated 
 * 									resources and mutexes.
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
			ft_safe_free((void **)&envp->philos[i].pos_char);
			i++;
		}
		ft_safe_free((void **)&envp->philos);
	}
	ft_safe_free((void **)&envp->forks);
}

void	ft_safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
