/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:05:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 23:22:53 by rdel-olm         ###   ########.fr       */
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
 * The function "ft_check_dead" monitors the simulation for philosopher deaths 
 * or completion of eating goals. It continuously checks whether a philosopher 
 * has exceeded their time to die or if all philosophers have reached their 
 * eating limit. The function terminates the simulation if either condition 
 * is met.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing shared data and flags.
 * @param t_philo *philo			An array of philosopher structures to 
 * 									monitor.
 * 
 * @return void
 * 
 * The function "ft_check_dead_aux" checks if all philosophers have reached 
 * their eating limit and updates the `eat_max` flag in the simulation 
 * environment. It ensures thread-safe access to the `eat_max` flag by using 
 * the `writing` mutex.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing the shared data.
 * @param t_philo *philo			An array of philosopher structures to check 
 * 									for eating limits.
 * @param int i						A temporary counter used for iteration.
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
	unsigned long	start_time;

	start_time = ft_get_time();
	while (!envp->stopping_rule)
	{
		if (ft_get_time() - start_time >= total_time)
			break ;
		usleep(envp->nbr_philos * 3);
	}
	return ;
}

void	ft_check_think(unsigned long time, t_envp *envp)
{
	ft_check_sleep(time, envp);
}

static void	ft_check_dead_aux(t_envp *envp, t_philo *philo, int i)
{
	pthread_mutex_lock(&envp->writing);
	i = 0;
	while (envp->philo_eat_limit && i < envp->nbr_philos \
	&& philo[i].times_eaten >= envp->philo_eat_limit)
		i++;
	envp->eat_max = (i == envp->nbr_philos);
	pthread_mutex_unlock(&envp->writing);
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
				ft_check_stamp(RED DIED RESET "\n", &philo[i], UNLOCK);
				pthread_mutex_lock(&envp->writing);
				envp->stopping_rule = 1;
				pthread_mutex_unlock(&envp->writing);
			}
			pthread_mutex_unlock(&envp->mealtime);
			i++;
		}
		if (envp->stopping_rule)
			break ;
		ft_check_dead_aux(envp, philo, i);
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
