/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:58:55 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 21:41:03 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_init_philo" initializes the philosopher structures. Each 
 * philosopher is assigned a position, a character representation of their 
 * position, their left and right forks, and a reference to the simulation 
 * environment. It ensures proper cleanup if memory allocation fails.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing the philosophers 
 * 									array.
 * 
 * @return int						Returns EXIT_SUCCESS if all philosophers 
 * 									are successfully initialized. Returns 
 * 									EXIT_FAILURE if memory allocation fails.
 * 
 * The function "ft_init_sim" initializes the simulation environment, including 
 * the allocation of memory for philosopher structures and forks, 
 * initialization of mutexes, and setup of philosopher-specific data. It 
 * ensures proper cleanup if any initialization step fails.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing all resources.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									is successfully initialized. Returns 
 * 									EXIT_FAILURE if any allocation or 
 * 									initialization step fails.
 * 
 */

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
		{
			while (--i >= 0)
				free(envp->philos[i].pos_char);
			return (EXIT_FAILURE);
		}
		envp->philos[i].right_fork = i;
		envp->philos[i].left_fork = (i + 1) % envp->nbr_philos;
		envp->philos[i].envp = envp;
		i++;
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
	if (ft_init_mutex_safe(envp) == EXIT_FAILURE)
	{
		ft_clean_resources(envp);
		return (EXIT_FAILURE);
	}
	if (ft_init_philo(envp) == EXIT_FAILURE)
	{
		ft_clean_resources(envp);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
