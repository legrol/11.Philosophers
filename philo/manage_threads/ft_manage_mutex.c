/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:47:43 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 21:25:47 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_init_mutex_safe" initializes all mutexes for the simulation 
 * environment. If any mutex initialization fails, it destroys all previously 
 * initialized mutexes to ensure no resources are leaked.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure that holds the mutexes.
 * 
 * @return int						Returns EXIT_SUCCESS if all mutexes are 
 * 									successfully initialized. Returns 
 * 									EXIT_FAILURE if any mutex initialization 
 * 									fails.
 * 
 * The function "ft_destroy_all_mutexes" destroys all mutexes associated with 
 * the simulation. This is called during cleanup when all mutexes are fully 
 * initialized.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing mutexes.
 * 
 * @return void
 * 
 * The function "ft_destroy_partial_mutexes" destroys a specified number 
 * of mutexes that were initialized during a failed initialization process. 
 * It ensures that partially initialized resources are properly cleaned up.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing mutexes.
 * @param int initialized_count		The number of mutexes that were 
 * 									successfully initialized and need to be 
 * 									destroyed.
 * 
 * @return void
 * 
 */

void	ft_destroy_partial_mutexes(t_envp *envp, int initialized_count)
{
	int	i;

	i = 0;
	while (i < initialized_count)
	{
		pthread_mutex_destroy(&(envp->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(envp->mealtime));
	pthread_mutex_destroy(&(envp->writing));
}

void	ft_destroy_all_mutexes(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		pthread_mutex_destroy(&(envp->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(envp->mealtime));
	pthread_mutex_destroy(&(envp->writing));
}

int	ft_init_mutex_safe(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		if (pthread_mutex_init(&(envp->forks[i]), NULL))
		{
			ft_destroy_partial_mutexes(envp, i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_mutex_init(&(envp->mealtime), NULL) || \
	pthread_mutex_init(&(envp->writing), NULL))
	{
		ft_destroy_partial_mutexes(envp, i);
	}
	return (EXIT_SUCCESS);
}
