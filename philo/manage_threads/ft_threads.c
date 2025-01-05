/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:38:24 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 19:16:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_create_threads_and_monitor" creates threads for all 
 * philosophers and starts their routines. It also monitors the simulation 
 * for stopping conditions and cleans up resources when the simulation ends.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing philosopher and simulation data.
 * 
 * @return int						Returns EXIT_SUCCESS if all threads are 
 * 									created and monitored successfully. Returns 
 * 									EXIT_FAILURE if thread creation fails.
 * 
 * The function "ft_philosopher_routine" represents the behavior of a single 
 * philosopher during the simulation. It alternates between eating, sleeping, 
 * and thinking, while continuously checking for stopping conditions.
 * 
 * @param void *args				A pointer to the philosopher structure, 
 * 									which contains the philosopher's state 
 * 									and environment.
 * 
 * @return void*					Returns NULL after the philosopher exits 
 * 									the routine.
 * 
 * The function "ft_lock_shutdown_flag" retrieves the value of the simulation's 
 * stopping rule in a thread-safe manner. It ensures that the `stopping_rule` 
 * flag is accessed safely using a mutex.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the stopping rule flag and its 
 * 									mutex.
 * 
 * @return int						Returns the current value of the 
 * 									`stopping_rule` flag.
 * 
 */

int	ft_lock_shutdown_flag(t_envp *envp)
{
	int	shutdown_flag;

	pthread_mutex_lock(&envp->stopping_mutex);
	shutdown_flag = envp->stopping_rule;
	pthread_mutex_unlock(&envp->stopping_mutex);
	return (shutdown_flag);
}

static void	*ft_philosopher_routine(void *args)
{
	t_philo	*philo;
	t_envp	*envp;
	int		shutdown_flag;
	int		eat_max_flag;

	philo = (t_philo *)args;
	envp = philo->envp;
	if (philo->pos % 2 && envp->nbr_philos > 1)
		ft_check_sleep(envp->time_to_eat * 2, envp);
	while (1)
	{
		shutdown_flag = ft_lock_shutdown_flag(envp);
		pthread_mutex_lock(&envp->mutex_eat_max);
		eat_max_flag = envp->eat_max;
		pthread_mutex_unlock(&envp->mutex_eat_max);
		if (shutdown_flag || eat_max_flag)
			break ;
		ft_check_eat(philo);
		ft_check_stamp(ORANGE SLEEP RESET, philo, UNLOCK);
		ft_check_sleep(envp->time_to_sleep, envp);
		ft_check_stamp(YELLOW THINK RESET, philo, UNLOCK);
	}
	return (NULL);
}

int	ft_create_threads_and_monitor(t_envp *envp)
{
	int	i;

	i = 0;
	envp->init_time = ft_get_time();
	while (i < envp->nbr_philos)
	{
		envp->philos[i].last_meal = ft_get_time();
		if (pthread_create(&envp->philos[i].thread_id, NULL, \
		ft_philosopher_routine, &(envp->philos[i])))
			return (EXIT_FAILURE);
		i++;
	}
	ft_check_dead(envp, envp->philos);
	ft_exit_threads(envp);
	return (EXIT_SUCCESS);
}
