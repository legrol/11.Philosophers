/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:09:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/19 21:09:12 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_init_struct" initializes the simulation's environment 
 * structure (`t_envp`) with values derived from the command-line arguments. 
 * It sets default values for optional fields and prepares the structure for 
 * further use in the simulation.
 * 
 * @param int argc					The number of command-line arguments 
 * 									passed to the program.
 * @param char **argv				An array of strings containing the 
 * 									command-line arguments. Expected arguments 
 * 									include the number of philosophers, time 
 * 									to die, time to eat, time to sleep, and 
 * 									an optional maximum number of meals.
 * @param t_envp *env				A pointer to the simulation environment 
 * 									structure to be initialized.
 * 
 * @return int						Returns EXIT_SUCCESS after successful 
 * 									initialization. 
 * 
 */

int	ft_init_struct(int argc, char **argv, t_envp *envp)
{
	envp->death = NULL;
	envp->stop = NULL;
	envp->write = NULL;
	envp->forks = NULL;
	envp->nbr_philos = ft_philo_atoi(argv[1]);
	envp->time_to_die = ft_philo_atoi(argv[2]);
	envp->time_to_eat = ft_philo_atoi(argv[3]);
	envp->time_to_sleep = ft_philo_atoi(argv[4]);
	envp->philo_eat_limit = -1;
	envp->current_eat = -1;
	envp->eat_counter = -1;
	if (argc == 6)
	{
		envp->eat_counter = 0;
		envp->current_eat = 0;
		envp->philo_eat_limit = ft_philo_atoi(argv[5]);
	}
	return (EXIT_SUCCESS);
}
