/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:38:24 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 21:21:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_create_threads_and_monitor" initializes philosopher threads, 
 * starts the simulation, and monitors its progress. It ensures proper cleanup 
 * if thread creation fails and finalizes resources once the simulation ends.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing all shared data 
 * 									and thread management resources.
 * 
 * @return int						Returns EXIT_SUCCESS if the threads are 
 * 									created and monitored successfully. Returns 
 * 									EXIT_FAILURE if thread creation fails or 
 * 									another error occurs.
 * 
 * The function "ft_philosopher_routine" defines the behavior of each 
 * philosopher during the simulation. Philosophers alternate between eating, 
 * sleeping, and thinking until a stopping condition is met (e.g., a 
 * philosopher dies or the eating limit is reached).
 * 
 * @param void *args				A pointer to the philosopher's structure 
 * 									containing individual state and references 
 * 									to shared simulation data.
 * 
 * @return void*					Returns NULL when the philosopher thread 
 * 									terminates.
 * 
 * The function "ft_exit_threads" performs cleanup of resources related to 
 * philosopher threads. It joins or detaches threads, destroys all mutexes, 
 * and frees allocated memory for philosophers and forks.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing thread and resource 
 * 									information.
 * 
 * @return void
 * 
 * The function "ft_join_or_detach_threads" handles the proper termination of 
 * philosopher threads. It detaches a single thread if there is only one 
 * philosopher; otherwise, it joins all threads to ensure clean termination.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing thread information.
 * 
 * @return void
 * 
 */

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
	ft_destroy_all_mutexes(envp);
	free(envp->philos);
	free(envp->forks);
}

static void	*ft_philosopher_routine(void *args)
{
	t_philo	*philo;
	t_envp	*envp;

	philo = (t_philo *)args;
	envp = philo->envp;
	if (philo->pos % 2 && envp->nbr_philos > 1)
		ft_check_sleep(envp->time_to_eat / 50, envp);
	while (!envp->stopping_rule && !envp->eat_max)
	{
		ft_check_eat(philo);
		ft_check_sleep(envp->time_to_sleep / 2, envp);
		ft_check_stamp(ORANGE SLEEP RESET, philo, UNLOCK);
		ft_check_think(envp->time_to_think / 2, envp);
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
		{
			envp->stopping_rule = 1;
			ft_exit_threads(envp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	ft_check_dead(envp, envp->philos);
	pthread_mutex_unlock(&envp->writing);
	ft_exit_threads(envp);
	return (EXIT_SUCCESS);
}
