/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:11:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/14 15:32:36 by rdel-olm         ###   ########.fr       */
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

// void	ft_check_dead(t_envp *envp, t_philo *philo)
// {
// 	int	i;
// 	int	all_philos_full;

// 	while (!envp->eat_max)
// 	{
// 		i = 0;
// 		all_philos_full = 1;
// 		while (i < envp->nbr_philos && !envp->stopping_rule)
// 		{
// 			pthread_mutex_lock(&envp->mealtime);
// 			if ((int)(ft_get_time() - philo[i].last_meal) >= envp->time_to_die)
// 			{
// 				ft_check_stamp(RED DIED RESET, &philo[i], LOCK);
// 				envp->stopping_rule = 1;
// 			}
// 			pthread_mutex_unlock(&envp->mealtime);
// 			if (envp->philo_eat_limit && philo[i].times_eaten \
// 			< envp->philo_eat_limit)
// 				all_philos_full = 0;
// 			i++;
// 		}
// 		if (envp->stopping_rule)
// 			break ;
// 		envp->eat_max = all_philos_full;
// 	}
// }

// void	ft_check_eat(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->envp->forks[philo->right_fork]);
// 	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
// 	pthread_mutex_lock(&philo->envp->forks[philo->left_fork]);
// 	ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
// 	pthread_mutex_lock(&philo->envp->mealtime);
// 	ft_check_stamp(GREEN EAT RESET, philo, UNLOCK);
// 	philo->last_meal = ft_get_time();
// 	pthread_mutex_unlock(&philo->envp->mealtime);
// 	ft_sleep(philo->envp->time_to_eat, philo->envp);
// 	philo->times_eaten++;
// 	pthread_mutex_unlock(&philo->envp->forks[philo->right_fork]);
// 	pthread_mutex_unlock(&philo->envp->forks[philo->left_fork]);
// }

// void	ft_check_stamp(char *msg, t_philo *philo, int unlock)
// {
// 	char	*timestamp;

// 	timestamp = ft_philo_itoa(ft_get_time() - philo->envp->init_time);
// 	if (!timestamp)
// 		return ;
// 	pthread_mutex_lock(&philo->envp->writing);
// 	if (!philo->envp->stopping_rule && !philo->envp->eat_max)
// 		printf("%s %s %s\n", timestamp, philo->pos_char, msg);
// 	if (unlock)
// 		pthread_mutex_unlock(&philo->envp->writing);
// 	free(timestamp);
// }

void	ft_check_eat(t_philo *philo)
{
	t_envp	*envp;

	envp = philo->envp;
	sem_wait(&envp->forks[philo->pos - 1]);
	ft_check_stamp(BLUE "TAKEN_FORK" RESET, philo, 0);
	sem_wait(&envp->forks[philo->pos % envp->nbr_philos]);
	ft_check_stamp(BLUE "TAKEN_FORK" RESET, philo, 0);
	sem_wait(envp->mealtime);
	ft_check_stamp(GREEN "EAT" RESET, philo, 0);
	philo->last_meal = ft_get_time();
	sem_post(envp->mealtime);
	ft_sleep(envp->time_to_eat, envp);
	philo->times_eaten++;
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

static int	ft_check_dead_recursive(t_envp *envp, t_philo *philos, int index, \
int all_philos_full)
{
	if (index >= envp->nbr_philos)
	{
		envp->eat_max = all_philos_full;
		return (!envp->stopping_rule);
	}
	sem_wait(envp->mealtime);
	if ((int)(ft_get_time() - philos[index].last_meal) >= envp->time_to_die)
	{
		ft_check_stamp(RED "DIED" RESET, &philos[index], 1);
		envp->stopping_rule = 1;
	}
	sem_post(envp->mealtime);
	if (envp->philo_eat_limit && philos[index].times_eaten \
	< envp->philo_eat_limit)
		all_philos_full = 0;
	return (ft_check_dead_recursive(envp, philos, index + 1, all_philos_full));
}

void	ft_check_dead(t_envp *envp, t_philo *philo)
{
	while (!envp->eat_max && !envp->stopping_rule)
		ft_check_dead_recursive(envp, philo, 0, 1);
}

void	ft_destroy_semaphores_and_free(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		free(envp->philos[i].pos_char);
		sem_destroy(&envp->forks[i]);
		i++;
	}
	free(envp->philos);
	free(envp->forks);
	sem_destroy(envp->mealtime);
	sem_destroy(&envp->writing);
}
