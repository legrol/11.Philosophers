/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:05:25 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/08 21:46:59 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_check_stamp" prints a timestamped message for a 
 * philosopher's current action. It ensures thread-safe access to the output 
 * by locking the `writing` mutex. If `unlock` is set, the mutex is unlocked 
 * after printing.
 * 
 * @param char *msg					A string containing the message to print.
 * @param t_philo *philo			A pointer to the philosopher structure 
 * 									associated with the action.
 * @param int unlock				A flag indicating whether to unlock the 
 * 									`writing` mutex after printing (1 to 
 * 									unlock).
 * @return void
 * 
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
 */

void	ft_check_dead(t_envp *envp, t_philo *philo)
{
	int	i;
	int	all_philos_full;

	while (!envp->eat_max)
	{
		i = 0;
		all_philos_full = 1;
		while (i < envp->nbr_philos && !envp->stopping_rule)
		{
			pthread_mutex_lock(&envp->mealtime);
			if ((int)(ft_get_time() - philo[i].last_meal) >= envp->time_to_die)
			{
				ft_check_stamp("died", &philo[i], LOCK);
				envp->stopping_rule = 1;
			}
			pthread_mutex_unlock(&envp->mealtime);
			if (envp->philo_eat_limit && philo[i].times_eaten \
			< envp->philo_eat_limit)
				all_philos_full = 0;
			i++;
		}
		if (envp->stopping_rule)
			break ;
		envp->eat_max = all_philos_full;
	}
}

void	ft_check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->envp->forks[philo->right_fork]);
	ft_check_stamp("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->envp->forks[philo->left_fork]);
	ft_check_stamp("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->envp->mealtime);
	ft_check_stamp("is eating", philo, UNLOCK);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->envp->mealtime);
	ft_sleep(philo->envp->time_to_eat, philo->envp);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->envp->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->envp->forks[philo->left_fork]);
}

void	ft_check_stamp(char *msg, t_philo *philo, int unlock)
{
	char	*timestamp;

	timestamp = ft_philo_itoa(ft_get_time() - philo->envp->init_time);
	if (!timestamp)
		return ;
	pthread_mutex_lock(&philo->envp->writing);
	if (!philo->envp->stopping_rule && !philo->envp->eat_max)
		printf("%s %s %s\n", timestamp, philo->pos_char, msg);
	if (unlock)
		pthread_mutex_unlock(&philo->envp->writing);
	free(timestamp);
}
