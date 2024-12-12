/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:38:24 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/08 21:48:34 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_create_threads_and_monitor" initializes threads for each 
 * philosopher, starts the simulation, and monitors their states for stopping 
 * conditions, such as a philosopher dying or all eating a defined maximum.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that holds simulation parameters and 
 * 									philosopher data.
 * @return int						Returns EXIT_SUCCESS if threads are 
 * 									created and monitored successfully; 
 * 									otherwise, returns EXIT_FAILURE.
 * 
 * The function "ft_philosopher_routine" defines the behavior of each 
 * philosopher in the simulation. Philosophers alternate between eating,
 * sleeping, and thinking, checking for stopping conditions and shared 
 * simulation states.
 * 
 * @param void *args				A pointer to the philosopher structure 
 * 									representing the philosopher's state.
 * @return void*					Returns NULL when the thread terminates.
 * 
 * The function "ft_exit_threads" handles the orderly termination of threads 
 * and cleanup of all simulation resources. It joins or detaches threads 
 * first, then destroys mutexes and frees dynamically allocated memory.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that holds simulation parameters and 
 * 									resources.
 * @return void
 * 
 * The function "ft_join_or_detach_threads" ensures that all philosopher 
 * threads are properly terminated. If there is only one philosopher, their 
 * thread is detached. Otherwise, it joins all philosopher threads to ensure 
 * proper cleanup after execution.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that holds the threads of all philosophers.
 * @return void
 * 
 * The function "ft_destroy_mutexes_and_free" cleans up all resources
 * associated with the philosophers and the simulation. It destroys all 
 * mutexes, frees dynamically allocated memory for the philosopher structures,
 * and releases the memory for forks.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that holds simulation parameters, mutexes, 
 * 									and philosopher data.
 * @return void
 * 
 */

static void	ft_destroy_mutexes_and_free(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		pthread_mutex_destroy(&envp->forks[i]);
		free(envp->philos[i].pos_char);
		i++;
	}
	pthread_mutex_destroy(&envp->mealtime);
	pthread_mutex_destroy(&envp->writing);
	free(envp->philos);
	free(envp->forks);
}

static void	ft_join_or_detach_threads(t_envp *envp)
{
	int	i;

	if (envp->nbr_philos == 1)
	{
		pthread_detach(envp->philos[0].thread_id);
		return ;
	}
	i = 0;
	while (i < envp->nbr_philos)
	{
		pthread_join(envp->philos[i].thread_id, NULL);
		i++;
	}
}

static void	ft_exit_threads(t_envp *envp)
{
	ft_join_or_detach_threads(envp);
	ft_destroy_mutexes_and_free(envp);
}

static void	*ft_philosopher_routine(void *args)
{
	t_philo	*philo;
	t_envp	*envp;

	philo = (t_philo *)args;
	envp = philo->envp;
	if (philo->pos % 2 && envp->nbr_philos > 1)
		ft_sleep(envp->time_to_eat / 50, envp);
	while (!envp->stopping_rule && !envp->eat_max)
	{
		ft_check_eat(philo);
		ft_check_stamp("is sleeping", philo, UNLOCK);
		ft_sleep(envp->time_to_sleep, envp);
		ft_check_stamp("is thinking", philo, UNLOCK);
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
	pthread_mutex_unlock(&envp->writing);
	ft_exit_threads(envp);
	return (EXIT_SUCCESS);
}
