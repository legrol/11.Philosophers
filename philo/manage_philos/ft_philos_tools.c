/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:09:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:07 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_eat_max_flag" retrieves the current value of the `eat_max` 
 * flag from the environment structure in a thread-safe manner. This flag 
 * indicates whether all philosophers have reached their eating limit.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the `eat_max` flag.
 * 
 * @return int						Returns the current value of the 
 * 									`eat_max` flag.
 * 
 * The function "ft_verify_stop" checks if a philosopher has exceeded their 
 * time to die. If so, it triggers the stopping condition for the simulation 
 * by updating the `stopping_rule` flag in a thread-safe manner.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									being verified.
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing simulation data.
 * 
 * @return void
 * 
 * The function "ft_check_eat_max" checks if all philosophers have reached 
 * the eating limit specified in the simulation. It updates the `eat_max` 
 * flag in a thread-safe manner to indicate whether the condition has been met.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing simulation parameters.
 * @param t_philo *philo			An array of philosopher structures to 
 * 									check for eating limits.
 * 
 * @return void
 * 
 * The function "ft_print_dead" prints the death message of a philosopher. 
 * It calculates an adjusted timestamp for the message to simulate real-time 
 * output consistency and ensures thread-safe access to the `writing` mutex.
 * 
 * @param t_philo *philo			A pointer to the philosopher's structure.
 * @param char *msg					The death message to be printed.
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing shared simulation data.
 * 
 * @return void
 *  
 */

void	ft_print_dead(t_philo *philo, char *msg, t_envp *envp)
{
	int	adjusted_time;

	pthread_mutex_lock(&philo->envp->writing);
	adjusted_time = envp->last_time_status + 10;
	printf("%d\t" WHITE "%s " RESET RED "%s\n\n" RESET, adjusted_time, \
	philo->pos_char, msg);
	pthread_mutex_unlock(&philo->envp->writing);
}

void	ft_check_eat_max(t_envp *envp, t_philo *philo)
{
	int	i;

	i = 0;
	while (envp->philo_eat_limit && i < envp->nbr_philos)
	{
		pthread_mutex_lock(&philo[i].philo_mutex);
		if (philo[i].times_eaten < envp->philo_eat_limit)
		{
			pthread_mutex_unlock(&philo[i].philo_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo[i].philo_mutex);
		i++;
	}
	pthread_mutex_lock(&envp->mutex_eat_max);
	envp->eat_max = (i == envp->nbr_philos);
	pthread_mutex_unlock(&envp->mutex_eat_max);
}

void	ft_verify_stop(t_philo *philo, t_envp *envp)
{
	pthread_mutex_lock(&envp->mealtime);
	if ((int)(ft_get_time() - philo->last_meal) >= envp->time_to_die)
	{
		ft_check_stamp(DIED, philo, LOCK);
		pthread_mutex_lock(&envp->stopping_mutex);
		envp->stopping_rule = 1;
		pthread_mutex_unlock(&envp->stopping_mutex);
	}
	pthread_mutex_unlock(&envp->mealtime);
}

int	ft_eat_max_flag(t_envp *envp)
{
	int	eat_max_flag;

	pthread_mutex_lock(&envp->mutex_eat_max);
	eat_max_flag = envp->eat_max;
	pthread_mutex_unlock(&envp->mutex_eat_max);
	return (eat_max_flag);
}
