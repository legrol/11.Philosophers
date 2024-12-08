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
 * The function "ft_create_threads" initializes the philosopher threads and 
 * starts the simulation. It assigns each philosopher a thread that runs the 
 * `myroutine` function and monitors the simulation for stopping conditions.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that manages simulation parameters, threads, 
 * 									and shared state.
 * @return int						Returns EXIT_SUCCESS if all threads are 
 * 									created successfully; otherwise, returns 
 * 									EXIT_FAILURE.
 * 
 * The function "myroutine" is the main routine executed by each philosopher's 
 * thread. It alternates between eating, sleeping, and thinking, checking for 
 * stopping conditions and updating simulation states.
 * 
 * @param void *args				A pointer to the philosopher's structure 
 * 									containing individual philosopher data 
 * 									and a reference to the shared environment.
 * @return void*					Does not return; runs indefinitely until 
 * 									stopping conditions are met.
 * 
 * The function "exit_threads" handles the cleanup process for threads and 
 * other resources used during the simulation. It joins or detaches threads, 
 * destroys mutexes, and frees allocated memory for philosophers and forks.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that contains thread, mutex, and 
 * 									philosopher information.
 * @return void
 * 
 */

static void	exit_threads(t_envp *envp)
{
	int	i;

	if (envp->nbr_philos == 1)
		pthread_detach(envp->philos[0].thread_id);
	else
	{
		i = -1;
		while (++i < envp->nbr_philos)
			pthread_join(envp->philos[i].thread_id, NULL);
	}
	i = -1;
	while (++i < envp->nbr_philos)
		pthread_mutex_destroy(&envp->forks[i]);
	pthread_mutex_destroy(&envp->mealtime);
	pthread_mutex_destroy(&envp->writing);
	i = -1;
	while (++i < envp->nbr_philos)
		free(envp->philos[i].pos_char);
	free(envp->philos);
	free(envp->forks);
}

static void	*myroutine(void *args)
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

int	ft_create_threads(t_envp	*envp)
{
	int	i;

	i = 0;
	envp->init_time = ft_get_time();
	while (i < envp->nbr_philos)
	{
		envp->philos[i].last_meal = ft_get_time();
		if (pthread_create(&envp->philos[i].thread_id, NULL, \
		myroutine, &(envp->philos[i])))
			return (EXIT_FAILURE);
		i++;
	}
	ft_check_dead(envp, envp->philos);
	pthread_mutex_unlock(&envp->writing);
	exit_threads(envp);
	return (EXIT_SUCCESS);
}
