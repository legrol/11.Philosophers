/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:58:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 18:32:41 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_init_mutex" initializes all mutexes required for the 
 * simulation, including mutexes for forks, philosophers, and shared resources 
 * like mealtime and writing. It ensures that all mutexes are properly set up 
 * before the simulation begins.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the mutexes and simulation 
 * 									parameters.
 * 
 * @return int						Returns EXIT_SUCCESS if all mutexes are 
 * 									successfully initialized. Returns 
 * 									EXIT_FAILURE if any mutex initialization 
 * 									fails.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing philosopher data.
 * @param int i						The index of the philosopher being 
 * 									initialized.
 * 
 * @return int						Returns EXIT_SUCCESS if the philosopher is 
 * 									successfully initialized. Returns 
 * 									EXIT_FAILURE if memory allocation for 
 * 									`pos_char` fails.
 * 
 * The function "ft_init_philo" initializes all philosophers by calling 
 * "ft_init_data_philosophers" for each philosopher. If initialization fails, 
 * it frees any allocated memory for `pos_char` strings and returns 
 * EXIT_FAILURE.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing philosopher data.
 * 
 * @return int						Returns EXIT_SUCCESS if all philosophers 
 * 									are successfully initialized. Otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 * The function "ft_init_sim" initializes the entire simulation environment. 
 * It allocates memory for philosophers and forks, initializes all mutexes, 
 * and sets up philosopher-specific data. If any step fails, it ensures that 
 * all allocated resources are cleaned up before returning EXIT_FAILURE.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									managing simulation data and resources.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									is successfully initialized. Otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 */

int	ft_init_mutex(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		if (pthread_mutex_init(&(envp->forks[i]), NULL))
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&(envp->philos[i].philo_mutex), NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&(envp->mealtime), NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(envp->writing), NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(envp->stopping_mutex), NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&(envp->mutex_eat_max), NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_init_data_philosophers(t_envp *envp, int i)
{
	envp->philos[i].pos = i + 1;
	envp->philos[i].times_eaten = 0;
	envp->philos[i].pos_char = ft_philo_itoa(i + 1);
	if (!envp->philos[i].pos_char)
		return (EXIT_FAILURE);
	envp->philos[i].right_fork = i;
	envp->philos[i].left_fork = (i + 1) % envp->nbr_philos;
	envp->philos[i].envp = envp;
	return (EXIT_SUCCESS);
}

int	ft_init_philo(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		ft_init_data_philosophers(envp, i);
		i++;
	}
	if (i != envp->nbr_philos)
	{
		while (i >= 0)
		{
			free(envp->philos[i].pos_char);
			i--;
		}
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_init_sim(t_envp *envp)
{
	envp->philos = (t_philo *)malloc(sizeof(t_philo) * envp->nbr_philos);
	if (!envp->philos)
		return (EXIT_FAILURE);
	envp->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	envp->nbr_philos);
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
