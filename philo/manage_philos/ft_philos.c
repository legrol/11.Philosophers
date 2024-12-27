/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:05:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/19 20:11:55 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** 
 * The function "ft_check_eat" manages the eating process for a philosopher. 
 * It locks the forks, updates the philosopher's last meal time, and 
 * increments the `times_eaten` counter. After eating, it unlocks the forks 
 * and sleeps for the time specified in `time_to_eat`.
 * 
 * @param t_philo *philo			A pointer to the philosopher structure 
 * 									representing the philosopher that is 
 * 									eating.
 * @return void
 * 
 * The function "ft_check_dead" monitors the philosophers' status to determine 
 * if any philosopher has exceeded their `time_to_die` without eating or if 
 * all philosophers have reached the specified eating limit 
 * (`philo_eat_limit`). 
 * If a philosopher dies, it sets the `stopping_rule` and prints a death 
 * message. 
 * If all philosophers are full, it updates the `eat_max` flag.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that stores the simulation parameters and 
 * 									state variables.
 * @param t_philo *philo			A pointer to the array of philosophers' 
 * 									structures that hold individual states.
 * 
 * @return void
 * 
 * The function "ft_check_think" simulates the thinking process of a 
 * philosopher by calling `ft_check_sleep` with the specified thinking 
 * duration. It allows the thinking process to be interrupted if the 
 * simulation's stopping condition (`stopping_rule`) is triggered.
 * 
 * @param unsigned long time		The duration of the thinking process in 
 * 									milliseconds.
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure that contains the stopping 
 * 									condition.
 * 
 * @return void
 * 
 * The function "ft_check_sleep" pauses execution for a specified duration 
 * in milliseconds (`total_time`). It continuously checks whether the 
 * simulation's stopping condition (`stopping_rule`) has been triggered, 
 * allowing the sleep process to be interrupted if necessary.
 * 
 * @param unsigned long total_time	The duration of the sleep in milliseconds.
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure that contains the stopping 
 * 									condition.
 * 
 * @return void
 * 
 */

void	ft_check_sleep(unsigned long total_time, t_envp *envp)
{
	unsigned long	init;

	init = ft_get_time();
	while (!envp->stopping_rule)
	{
		if (ft_get_time() - init >= total_time)
			break ;
		usleep(envp->nbr_philos * 3);
	}
	return ;
}

void	ft_check_think(unsigned long time, t_envp *envp)
{
	ft_check_sleep(time, envp);
}

void	ft_check_dead(t_envp *envp, t_philo *philo)
{
	int	i;

	while (!envp->eat_max)
	{
		i = 0;
		while (i < envp->nbr_philos && !envp->stopping_rule)
		{
			pthread_mutex_lock(&envp->mealtime);
			if ((int)(ft_get_time() - philo[i].last_meal) >= envp->time_to_die)
			{
				ft_check_stamp(RED DIED RESET "\n", &philo[i], LOCK);
				envp->stopping_rule = 1;
			}
			pthread_mutex_unlock(&envp->mealtime);
			i++;
		}
		if (envp->stopping_rule)
			break ;
		i = 0;
		while (envp->philo_eat_limit && i < envp->nbr_philos
			&& philo[i].times_eaten >= envp->philo_eat_limit)
			i++;
		envp->eat_max = (i == envp->nbr_philos);
	}
	ft_finish_sim(envp);
}

void	ft_check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->envp->forks[philo->right_fork]);
	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	pthread_mutex_lock(&philo->envp->forks[philo->left_fork]);
	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	pthread_mutex_lock(&philo->envp->mealtime);
	ft_check_stamp(GREEN EAT RESET, philo, UNLOCK);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->envp->mealtime);
	ft_check_sleep(philo->envp->time_to_eat, philo->envp);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->envp->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->envp->forks[philo->left_fork]);
}
