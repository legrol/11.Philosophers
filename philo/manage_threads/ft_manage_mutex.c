/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:47:43 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 19:14:32 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_exit_threads" handles the cleanup process at the end 
 * of the simulation. It ensures that the simulation results are printed 
 * if not already done, threads are joined or detached, mutexes are destroyed, 
 * and all dynamically allocated resources are freed.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing all simulation resources.
 * 
 * @return void
 * 
 * The function "ft_join_or_detach_threads" ensures that all philosopher 
 * threads are either joined or detached. For a single philosopher, the 
 * thread is detached; for multiple philosophers, their threads are joined 
 * to ensure proper cleanup.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing thread data.
 * 
 * @return void
 * 
 * The function "ft_destroy_mutexes_and_free" destroys all mutexes 
 * initialized for the simulation, including those associated with forks, 
 * philosophers, and shared resources. This ensures proper cleanup of 
 * synchronization primitives.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the mutexes and simulation 
 * 									state.
 * 
 * @return void
 * 
 * The function "ft_free_philo" frees the dynamically allocated memory for 
 * the philosophers and forks arrays. It ensures that all dynamically 
 * allocated resources for philosopher-related data are properly released.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the philosophers and forks data.
 * 
 * @return void
 * 
 */

static void	ft_free_philo(t_envp *envp)
{
	int	i;

	i = -1;
	while (++i < envp->nbr_philos)
		free(envp->philos[i].pos_char);
	free(envp->philos);
	free(envp->forks);
}

static void	ft_destroy_mutexes_and_free(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		pthread_mutex_destroy(&envp->forks[i]);
		pthread_mutex_destroy(&envp->philos[i].philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&envp->mealtime);
	pthread_mutex_destroy(&envp->writing);
	pthread_mutex_destroy(&envp->stopping_mutex);
	pthread_mutex_destroy(&envp->mutex_eat_max);
}

static void	ft_join_or_detach_threads(t_envp *envp)
{
	int	i;

	if (envp->nbr_philos == 1)
		pthread_detach(envp->philos[0].thread_id);
	else
	{
		i = 0;
		while (i < envp->nbr_philos)
		{
			pthread_join(envp->philos[i].thread_id, NULL);
			i++;
		}
	}
}

void	ft_exit_threads(t_envp *envp)
{
	if (!envp->stopping_rule)
		ft_finish_sim(envp);
	ft_join_or_detach_threads(envp);
	ft_destroy_mutexes_and_free(envp);
	ft_free_philo(envp);
}
