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

#include "../includes/philosophers.h"

/**
 * The function "ft_init_sim" allocates memory for the philosophers and their 
 * forks, and initializes all the necessary mutexes and philosopher data 
 * structures. If any initialization step fails, it cleans up the allocated 
 * resources and exits.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that stores simulation parameters, 
 * 									mutexes, and philosopher data.
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									is successfully initialized; otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 * The function "ft_init_mutex" initializes the mutexes for the philosophers' 
 * forks, as well as additional mutexes for managing shared resources such as 
 * mealtime and writing operations.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that stores the mutexes and simulation 
 * 									parameters.
 * @return int						Returns EXIT_SUCCESS if all mutexes are 
 * 									successfully initialized; otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 * The function "ft_init_philo" initializes the philosophers' data in the 
 * environment structure. It assigns positions, fork associations, and other 
 * relevant details to each philosopher. If an error occurs during the 
 * initialization (e.g., memory allocation fails), it cleans up and exits.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that stores simulation parameters and 
 * 									philosopher data.
 * @return int						Returns EXIT_SUCCESS if the philosophers 
 * 									are successfully initialized; otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 */

int	ft_init_philo(t_envp *envp)
{
	int	i;

	i = 0;
	//printf("\ntot_philo: %i\n\n", envp->nbr_philos);
	while (i < envp->nbr_philos)
	{
		envp->philos[i].pos = i + 1;
		//printf("pos: %i, i: %i\n", envp->philos[i].pos, i);
		envp->philos[i].times_eaten = 0;
		printf("times_eaten: %i, i: %i\n", envp->philos[i].times_eaten, i);
		envp->philos[i].pos_char = ft_philo_itoa(i + 1);
		//printf("pos_char: %s, i: %i\n", envp->philos[i].pos_char, i);
		if (!envp->philos[i].pos_char)
			break ;
		if (i == 0)
		{
			envp->philos[i].right_fork = envp->nbr_philos;
			//printf("right_fork: %i, i: %i\n", envp->philos[i].right_fork, i);
		}
		else
		{
			envp->philos[i].right_fork = i;
			//printf("right_fork: %i, i: %i\n", envp->philos[i].right_fork, i);
		}
		envp->philos[i].left_fork = (i + 1);
		//printf("left_fork: %i, i: %i\n\n", envp->philos[i].left_fork, i);
		envp->philos[i].envp = envp;
		i++;
	}
	if (i != envp->nbr_philos)
	{
		while (i-- >= 0)
			free(envp->philos[i].pos_char);
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
		//FALLA EN FT_INIT_PHILO en philo_itoa
		free(envp->philos);
		free(envp->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
