/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:09:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/31 19:55:46 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_finish_sim" finalizes the simulation by printing a summary 
 * if the simulation ends due to all philosophers reaching their eating limit 
 * (`eat_max`) or the stopping condition (`stopping_rule`) being triggered. 
 * The summary includes the number of philosophers and the eating limit.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure containing the simulation state 
 * 									and parameters.
 * 
 * @return void
 * 
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
 */

void	ft_check_stamp(char *msg, t_philo *philo, int unlock)
{
	char	*timestamp;

	timestamp = ft_philo_itoa(ft_get_time() - philo->envp->init_time);
	if (!timestamp)
		return ;
	pthread_mutex_lock(&philo->envp->writing);
	if (!philo->envp->stopping_rule && !philo->envp->eat_max)
	{
		printf("%s\t" WHITE "%s " RESET "%s\n", timestamp, philo->pos_char, \
		msg);
	}
	if (unlock)
		pthread_mutex_unlock(&philo->envp->writing);
	free(timestamp);
}

void	ft_finish_sim(t_envp *envp)
{
	if (envp->eat_max || envp->stopping_rule)
	{
		printf("\n" DONE "\n");
		printf(GREEN "%d" RESET PHILO_EATEN GREEN "%d " RESET TIMES "\n\n",
			envp->nbr_philos, envp->philo_eat_limit);
	}
}
