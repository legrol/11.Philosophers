/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:05:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/30 22:02:49 by rdel-olm         ###   ########.fr       */
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
	// unsigned long	init;

	// init = ft_get_time();
	// while (!envp->stopping_rule)
	// {
	// 	if (ft_get_time() - init >= total_time)
	// 		break ;
	// 	usleep(envp->nbr_philos * 3);
	// }
	// return ;

	unsigned long	init;

	init = ft_get_time();
	while (1)
	{
		pthread_mutex_lock(&envp->writing);
		if (envp->stopping_rule)
		{
			pthread_mutex_unlock(&envp->writing);
			break ;
		}
		pthread_mutex_unlock(&envp->writing);
		if (ft_get_time() - init >= total_time)
			break ;
		// usleep(envp->nbr_philos * 3);
		usleep(50);
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
	int	eaten_count;

	while (1)
	{
		i = 0;
		while (i < envp->nbr_philos)
		{
			pthread_mutex_lock(&philo[i].philo_mutex);
			if ((int)(ft_get_time() - philo[i].last_meal) >= envp->time_to_die)
			{
				ft_check_stamp(RED DIED RESET "\n", &philo[i], UNLOCK);
				pthread_mutex_lock(&envp->writing);
				envp->stopping_rule = 1;
				pthread_mutex_unlock(&envp->writing);
				pthread_mutex_unlock(&philo[i].philo_mutex);
				return ;
			}
			pthread_mutex_unlock(&philo[i].philo_mutex);
			i++;
		}
		pthread_mutex_lock(&envp->writing);
		if (envp->stopping_rule || envp->eat_max)
		{
			pthread_mutex_unlock(&envp->writing);
			break ;
		}
		pthread_mutex_unlock(&envp->writing);
		eaten_count = 0;
		i = 0;
		while (envp->philo_eat_limit && i < envp->nbr_philos)
		{
			pthread_mutex_lock(&philo[i].philo_mutex);
			if (philo[i].times_eaten >= envp->philo_eat_limit)
				eaten_count++;
			pthread_mutex_unlock(&philo[i].philo_mutex);
			i++;
		}
		pthread_mutex_lock(&envp->writing);
		envp->eat_max = (eaten_count == envp->nbr_philos);
		pthread_mutex_unlock(&envp->writing);
		if (envp->eat_max)
			break ;
	}
	ft_finish_sim(envp);
}

void	ft_check_eat(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(&philo->envp->forks[first_fork]);
	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	pthread_mutex_lock(&philo->envp->forks[second_fork]);
	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	pthread_mutex_lock(&philo->philo_mutex);
	ft_check_stamp(GREEN EAT RESET, philo, UNLOCK);
	philo->last_meal = ft_get_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->philo_mutex);
	ft_check_sleep(philo->envp->time_to_eat, philo->envp);
	pthread_mutex_unlock(&philo->envp->forks[first_fork]);
	pthread_mutex_unlock(&philo->envp->forks[second_fork]);
}
