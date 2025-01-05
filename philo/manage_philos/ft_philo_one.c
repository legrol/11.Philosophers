/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:16:15 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 18:40:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_check_sleep_one_philo" pauses the execution for a specified 
 * amount of time (in milliseconds) using a precise timing mechanism. This is 
 * used in the single-philosopher case to simulate waiting for the time-to-die.
 * 
 * @param unsigned long total_time	The amount of time (in milliseconds) to 
 * 									pause the execution.
 * 
 * @return void
 * 
 * The function "philo_routine_one_philo" simulates the behavior of a single 
 * philosopher. It locks a single fork, prints the actions (taking the fork 
 * and dying), and ensures proper mutex unlocking upon completion.
 * 
 * @param void *args				A pointer to the philosopher's structure 
 * 									containing its state and environment.
 * 
 * @return void*					Returns NULL after the simulation ends.
 * 
 * The function "initialize_resources" sets up the necessary resources for the 
 * single-philosopher simulation, including initializing the fork mutex, 
 * setting simulation parameters, and allocating the philosopher's position 
 * string.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing shared simulation data.
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									being initialized.
 * @param char *argv[]				Command-line arguments containing 
 * 									simulation parameters.
 * @param pthread_mutex_t *fork		A pointer to the mutex representing the 
 * 									single fork.
 * 
 * @return int						Returns EXIT_SUCCESS if initialization is 
 * 									successful. Otherwise, returns 
 * 									EXIT_FAILURE.
 * 
 * The function "ft_manage_on_philo" manages the simulation for a single 
 * philosopher. It initializes resources, starts the philosopher's routine 
 * in a thread, and performs cleanup after the simulation ends.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing shared simulation data.
 * @param char *argv[]				Command-line arguments containing 
 * 									simulation parameters.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									completes successfully. Otherwise, returns 
 * 									EXIT_FAILURE.
 * 
 */

static void	ft_check_sleep_one_philo(unsigned long total_time)
{
	unsigned long	init_time;

	init_time = ft_get_time();
	while (ft_get_time() - init_time < total_time)
		usleep(100);
}

static void	*philo_routine_one_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (!philo || !philo->envp || !philo->envp->forks)
	{
		ft_manage_err_simple(POINTER_ERR);
		return (NULL);
	}
	if (pthread_mutex_lock(philo->envp->forks) != 0)
	{
		perror(LOCK_MUTEX_ERR);
		return (NULL);
	}
	printf("%lu\t" WHITE "%d " RESET BLUE TAKEN_FORK RESET "\n", \
	ft_get_time() - philo->envp->init_time + 1, philo->pos);
	ft_check_sleep_one_philo(philo->envp->time_to_die);
	printf("%lu\t" WHITE "%d " RESET RED DIED RESET "\n\n", \
	ft_get_time() - philo->envp->init_time, philo->pos);
	if (pthread_mutex_unlock(philo->envp->forks) != 0)
		perror(UNLOCK_MUTEX_ERR);
	return (NULL);
}

static int	initialize_resources(t_envp *envp, t_philo *philo, char *argv[], \
pthread_mutex_t *fork)
{
	if (pthread_mutex_init(fork, NULL) != 0)
	{
		perror(INIT_MUTEX_ERR);
		return (EXIT_FAILURE);
	}
	philo->pos = 1;
	philo->pos_char = ft_philo_itoa(philo->pos);
	if (!philo->pos_char)
	{
		perror(ALLOC_POSCH_ERR);
		pthread_mutex_destroy(fork);
		return (EXIT_FAILURE);
	}
	envp->forks = fork;
	envp->time_to_die = ft_philo_atoi(argv[2]);
	envp->init_time = ft_get_time();
	philo->envp = envp;
	return (EXIT_SUCCESS);
}

int	ft_manage_on_philo(t_envp *envp, char *argv[])
{
	pthread_mutex_t	fork;
	t_philo			philo;

	if (initialize_resources(envp, &philo, argv, &fork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_create(&philo.thread_id, NULL, philo_routine_one_philo, \
	&philo) != 0)
	{
		perror(CREAT_THREAD_ERR);
		free(philo.pos_char);
		pthread_mutex_destroy(&fork);
		return (EXIT_FAILURE);
	}
	pthread_join(philo.thread_id, NULL);
	pthread_mutex_destroy(&fork);
	free(philo.pos_char);
	return (EXIT_SUCCESS);
}
