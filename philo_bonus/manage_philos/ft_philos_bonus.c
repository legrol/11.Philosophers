/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:11:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/19 21:14:05 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_routine" defines the main behavior of a philosopher in the 
 * simulation. It initializes a `pthread_t` thread to monitor the philosopher's
 * potential death (`ft_check_death`) and continuously alternates between 
 * eating, sleeping, and thinking until the simulation stops.
 * 
 * @param t_philo *philo			A pointer to the philosopher structure 
 * 									containing the philosopher's state and 
 * 									shared simulation envp.
 * 
 * @return void 
 * 
 */

void	ft_routine(t_philo *philo)
{
	pthread_t	death;

	philo->next_meal = ft_get_time() + (unsigned int)philo->envp->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		ft_check_eat(philo);
		ft_check_sleep(philo);
		ft_check_think(philo);
		usleep(500);
	}
}
