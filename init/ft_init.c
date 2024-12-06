/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:58:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/05 22:47:40 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_init" xxx
 * 
 * @param t_envp *envp				xxx
 * 
 * 
 */

int	ft_init_mutex(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		if (pthread_mutex_init(&(envp->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(envp->mealtime), NULL) || \
	pthread_mutex_init(&(envp->writing), NULL))
		return (1);
	// if (pthread_mutex_init(&(envp->writing), NULL))
	// 	return (1);
	return (0);
}

int	ft_init_philo(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		envp->philos[i].pos = i + 1;
		envp->philos[i].times_eaten = 0;
		envp->philos[i].pos_char = ft_philo_itoa(i + 1);
		if (!envp->philos[i].pos_char)
			break ;
		//
		//
		//
		i++;
	}




	return (0);
}

int	ft_init_sim(t_envp *envp)
{
	envp->philos = malloc(sizeof(t_philo) * envp->nbr_philos);
	if (!envp->philos)
		return (0);
	envp->forks = malloc(sizeof(pthread_mutex_t) * envp->nbr_philos);
	if (!envp->forks)
	{
		free(envp->philos);
		return (0);
	}
	if (ft_init_mutex(envp) || ft_init_philo(envp))
	{
		free(envp->philos);
		free(envp->forks);
		return (0);
	}
	// if (ft_init_philo(envp))
	// {
	// 	free(envp->philos);
	// 	free(envp->forks);
	// 	return (0);
	// }
	return (1);
}
