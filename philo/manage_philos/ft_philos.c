/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:05:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 19:10:20 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/** 
 * The function "ft_check_eat" simulates the eating action of a philosopher. 
 * It locks the necessary forks, updates the philosopher's last meal time 
 * and number of meals eaten, and then unlocks the forks.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure.
 * 
 * @return void
 * 
 * The function "ft_check_dead" continuously monitors the philosophers for 
 * death or simulation stopping conditions. It checks if any philosopher 
 * has exceeded their time-to-die or if all have reached their eating limit.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the simulation state.
 * @param t_philo *philo			An array of philosopher structures to 
 * 									monitor.
 * 
 * @return void
 * 
 * The function "ft_check_think" simulates the thinking action of a philosopher 
 * by calling "ft_check_sleep" for a specified duration.
 * 
 * @param unsigned long time		The amount of time (in milliseconds) the 
 * 									philosopher should think.
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the simulation state.
 * 
 * @return void
 * 
 * The function "ft_check_sleep" pauses the execution for a specified amount 
 * of time (in milliseconds) or until the simulation stopping condition is 
 * triggered. It checks the stopping rule in a thread-safe manner during the 
 * sleep period.
 * 
 * @param unsigned long total_time	The amount of time (in milliseconds) to 
 * 									pause the execution.
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the simulation state.
 * 
 * @return void
 *  
 */

void	ft_check_sleep(unsigned long total_time, t_envp *envp)
{
	unsigned long	init;
	int				shutdown_flag;

	init = ft_get_time();
	while (1)
	{
		pthread_mutex_lock(&envp->stopping_mutex);
		shutdown_flag = envp->stopping_rule;
		pthread_mutex_unlock(&envp->stopping_mutex);
		if (shutdown_flag)
			break ;
		if (ft_get_time() - init >= total_time)
			break ;
		usleep(100);
	}
}

void	ft_check_think(unsigned long time, t_envp *envp)
{
	ft_check_sleep(time, envp);
}

void	ft_check_dead(t_envp *envp, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		if (ft_eat_max_flag(envp))
			return ;
		if (ft_lock_shutdown_flag(envp))
			return ;
		while (i < envp->nbr_philos)
		{
			ft_verify_stop(philo, envp);
			if (ft_lock_shutdown_flag(envp))
				return ;
			i++;
		}
		ft_check_eat_max(envp, philo);
	}
	ft_finish_sim(envp);
}

void	ft_check_eat(t_philo *philo)
{
	if (philo->right_fork < philo->left_fork)
	{
		pthread_mutex_lock(&philo->envp->forks[philo->right_fork]);
		pthread_mutex_lock(&philo->envp->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->envp->forks[philo->left_fork]);
		pthread_mutex_lock(&philo->envp->forks[philo->right_fork]);
	}
	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	pthread_mutex_lock(&philo->envp->mealtime);
	ft_check_stamp(GREEN EAT RESET, philo, UNLOCK);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->envp->mealtime);
	pthread_mutex_unlock(&philo->envp->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->envp->forks[philo->left_fork]);
	ft_check_sleep(philo->envp->time_to_eat, philo->envp);
	pthread_mutex_lock(&philo->philo_mutex);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->philo_mutex);
}
