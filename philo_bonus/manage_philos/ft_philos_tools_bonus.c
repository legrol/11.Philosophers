/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_tools_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:13:16 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/18 17:22:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_check_death" monitors the philosopher's state for either 
 * starvation or completion of the required number of meals. If a philosopher 
 * dies or finishes eating, it logs the appropriate status and signals the 
 * simulation to stop.
 * 
 * @param void *arg					A pointer to the philosopher's structure 
 * 									representing their current state.
 * 
 * @return void*					Returns NULL when the monitoring thread 
 * 									terminates.
 * 
 * The function "ft_check_eat" manages the philosopher's eating process. It 
 * acquires forks, logs the eating action, updates the philosopher's meal 
 * time and counters, and releases the forks once eating is complete. 
 * If the philosopher has eaten the required number of meals, it updates the
 * shared counter.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									representing their current state.
 * 
 * @return void
 * 
 * The function "ft_manage_fork" handles the philosopher's acquisition of two
 * forks. It waits for the availability of each fork using semaphores and logs
 * the action of taking a fork.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									representing their current state.
 * 
 * @return void
 * 
 * The function "ft_check_sleep" logs the philosopher's action of sleeping 
 * and pauses for the duration of `time_to_sleep` to simulate the sleeping 
 * process. Philosophers with odd IDs stagger their sleep slightly for better 
 * synchronization.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									representing their current state.
 * 
 * @return void
 * 
 * The function "ft_check_think" logs the philosopher's action of thinking 
 * and then pauses for a duration equal to `time_to_sleep` to simulate the 
 * thinking process.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									representing their current state.
 * 
 * @return void
 * 
 */

void	ft_check_think(t_philo *philo)
{
	ft_log_status(THINK, philo);
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_check_sleep(t_philo *philo)
{
	ft_log_status(SLEEP, philo);
	if (philo->id % 2 && philo->data->philo_count > 1)
		usleep(philo->data->time_to_eat / 50);
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_manage_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_log_status(TAKEN_FORK, philo);
	usleep(100);
	sem_wait(philo->data->forks);
	ft_log_status(TAKEN_FORK, philo);
}

void	ft_check_eat(t_philo *philo)
{
	ft_manage_fork(philo);
	ft_log_status(EAT, philo);
	philo->last_meal = ft_get_time();
	philo->next_meal = philo->last_meal + \
	(unsigned int)philo->data->time_to_die;
	philo->eat_count++;
	if (philo->data->eat_counter != -1 && philo->eat_count >= \
	philo->data->eat_counter)
		philo->data->current_eat++;
	sem_post(philo->data->death);
	usleep(philo->data->time_to_eat * 1000);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->death);
		if (philo->next_meal < ft_get_time())
		{
			ft_log_status(DEAD, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
		sem_wait(philo->data->death);
		if (philo->data->current_eat != -1 && \
		philo->eat_count >= philo->data->max_eat + 1)
		{
			ft_log_status(DONE, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
	}
	return (NULL);
}
