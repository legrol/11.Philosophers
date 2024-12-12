/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:58:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/08 20:48:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_init_data_philosophers" initializes the data for each 
 * philosopher, including their position, fork associations, and a dynamically 
 * allocated string representation of their position. If memory allocation for
 * `pos_char` fails, it returns the index of the philosopher where the 
 * failure occurred.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing philosopher data and simulation 
 * 									parameters.
 * 
 * @return int						Returns -1 if initialization is successful. 
 * 									Otherwise, returns the index of the 
 * 									philosopher 
 * 									that failed to initialize.
 * 
 * The function "ft_init_philo" initializes all philosophers by calling 
 * "ft_init_data_philosophers". If initialization fails, it frees the 
 * allocated memory for the philosophers' `pos_char` strings and returns 
 * EXIT_FAILURE.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing philosopher data.
 * 
 * @return int						Returns EXIT_SUCCESS if initialization is 
 * 									successful. Otherwise, returns 
 * 									EXIT_FAILURE.
 * 
 * The function "ft_init_mutex" initializes mutexes for each fork, as well 
 * as additional mutexes for managing shared resources such as mealtime and 
 * writing. If any mutex initialization fails, it returns EXIT_FAILURE.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that contains the mutexes and other 
 * 									simulation parameters.
 * 
 * @return int						Returns EXIT_SUCCESS if all mutexes are 
 * 									successfully initialized. Otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 * The function "ft_init_sim" initializes the simulation environment. It 
 * allocates memory for the philosophers and forks, initializes mutexes, 
 * and sets up philosopher-specific data. If any initialization step fails, 
 * it cleans up all allocated resources and returns EXIT_FAILURE.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that manages simulation data and resources.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									is successfully initialized. Otherwise, 
 * 									returns EXIT_FAILURE. 
 * 
 */

static int	ft_init_data_philosophers(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		envp->philos[i].pos = i + 1;
		envp->philos[i].times_eaten = 0;
		envp->philos[i].pos_char = ft_philo_itoa(i + 1);
		if (!envp->philos[i].pos_char)
			return (i);
		envp->philos[i].right_fork = i;
		envp->philos[i].left_fork = (i + 1) % envp->nbr_philos;
		envp->philos[i].envp = envp;
		i++;
	}
	return (-1);
}

int	ft_init_philo(t_envp *envp)
{
	int	failed_index;

	failed_index = ft_init_data_philosophers(envp);
	if (failed_index != -1)
	{
		while (--failed_index >= 0)
			free(envp->philos[failed_index].pos_char);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_init_mutex(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		if (pthread_mutex_init(&(envp->forks[i]), NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&(envp->mealtime), NULL) || \
	pthread_mutex_init(&(envp->writing), NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_init_sim(t_envp *envp)
{
	envp->philos = malloc(sizeof(t_philo) * envp->nbr_philos);
	if (!envp->philos)
		return (EXIT_FAILURE);
	envp->forks = malloc(sizeof(pthread_mutex_t) * envp->nbr_philos);
	if (!envp->forks)
	{
		free(envp->philos);
		return (EXIT_FAILURE);
	}
	if (ft_init_mutex(envp) || ft_init_philo(envp))
	{
		free(envp->philos);
		free(envp->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
