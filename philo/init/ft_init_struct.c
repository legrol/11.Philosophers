/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:15:42 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/05 18:21:54 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_init_envp" initializes the environment structure with the 
 * simulation parameters provided as command-line arguments.
 * 
 * @param t_envp *envp    Pointer to the environment structure to initialize.
 * @param int argc        The number of command-line arguments.
 * @param char *argv[]    The array of command-line arguments.
 * 
 * @return                This function does not return a value. 
 * 
 */

void	ft_init_struct(t_envp *envp, int argc, char *argv[])
{
	envp->nbr_philos = 0;
	envp->time_to_die = 0;
	envp->time_to_eat = 0;
	envp->time_to_sleep = 0;
	envp->philo_eat_limit = 0;
	envp->nbr_philos = ft_philo_atoi(argv[1]);
	envp->time_to_die = ft_philo_atoi(argv[2]);
	envp->time_to_eat = ft_philo_atoi(argv[3]);
	envp->time_to_sleep = ft_philo_atoi(argv[4]);
	if (argc == 6)
		envp->philo_eat_limit = ft_philo_atoi(argv[5]);
}
