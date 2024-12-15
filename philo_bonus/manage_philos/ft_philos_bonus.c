/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:11:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/15 20:30:02 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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

void	ft_check_eat(t_philo *philo)
{
	t_envp	*envp;

	envp = philo->envp;
	sem_wait(&envp->forks[philo->pos - 1]);
	ft_check_stamp("has taken a fork", philo, 1);
	sem_wait(&envp->forks[philo->pos % envp->nbr_philos]);
	ft_check_stamp("has taken a fork", philo, 1);
	sem_wait(envp->mealtime);
	ft_check_stamp("is eating", philo, 1);
	philo->last_meal = ft_get_time();
	philo->times_eaten++;
	sem_post(envp->mealtime);
	if (philo->times_eaten == envp->philo_eat_limit)
		sem_post(envp->meals_done);
	ft_sleep(envp->time_to_eat, envp);
	sem_post(&envp->forks[philo->pos - 1]);
	sem_post(&envp->forks[philo->pos % envp->nbr_philos]);
}

void	ft_check_stamp(char *msg, t_philo *philo, int unlock)
{
	char	*timestamp;

	timestamp = ft_philo_itoa(ft_get_time() - philo->envp->init_time);
	if (!timestamp)
		return ;
	sem_wait(&philo->envp->writing);
	if (!philo->envp->stopping_rule && !philo->envp->eat_max)
		printf("%s %s %s\n", timestamp, philo->pos_char, msg);
	if (unlock)
		sem_post(&philo->envp->writing);
	free(timestamp);
}

static void	ft_check_dead_recursive(t_envp *envp, t_philo *philo, int index)
{
	unsigned long	time_since_last_meal;

	if (index >= envp->nbr_philos)
		return ;
	sem_wait(envp->mealtime);
	time_since_last_meal = ft_get_time() - philo[index].last_meal;
	if ((int)time_since_last_meal >= envp->time_to_die)
	{
		sem_wait(&envp->writing);
		printf("%lu %d %s\n", ft_get_time() - envp->init_time, \
		philo[index].pos, "died");
		envp->stopping_rule = 1;
		sem_post(&envp->writing);
		sem_post(envp->mealtime);
		return ;
	}
	sem_post(envp->mealtime);
	ft_check_dead_recursive(envp, philo, index + 1);
}

void	ft_check_dead(t_envp *envp, t_philo *philo)
{
	int	meals_done;

	meals_done = 0;
	while (!envp->stopping_rule)
	{
		usleep (1000);
		ft_check_dead_recursive(envp, philo, 0);
		if (envp->philo_eat_limit > 0)
		{
			sem_wait(envp->meals_done);
			meals_done++;
			if (meals_done == envp->nbr_philos)
			{
				envp->stopping_rule = 1;
				return ;
			}
		}
	}
}

void	ft_destroy_semaphores_and_free(t_envp *envp)
{
	sem_close(envp->forks);
	sem_close(envp->mealtime);
	sem_close(&envp->writing);
	sem_close(envp->meals_done);
	sem_unlink("/forks");
	sem_unlink("/mealtime");
	sem_unlink("/writing");
	sem_unlink("/meals_done");
	free(envp->philos);
}
