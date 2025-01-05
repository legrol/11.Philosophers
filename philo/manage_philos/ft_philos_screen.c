/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:49:30 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 19:06:10 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_finish_sim" prints a summary of the simulation results, 
 * including the total number of philosophers and the eating limit, if the 
 * simulation ends due to all philosophers reaching the eating limit or 
 * the stopping rule being triggered.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the simulation data.
 * 
 * @return void
 * 
 * The function "ft_check_stamp" generates a timestamp and uses 
 * "ft_print_message" to print the philosopher's current status. It handles 
 * mutex unlocking and memory cleanup for the timestamp string.
 * 
 * @param char *msg					The message describing the philosopher's 
 * 									current status.
 * @param t_philo *philo			A pointer to the philosopher's structure.
 * @param int unlock				Flag indicating whether to unlock the 
 * 									writing mutex after printing.
 * 
 * @return void
 * 
 * The function "ft_print_message" prints a message indicating the current 
 * status of a philosopher. It also checks simulation stopping conditions 
 * (e.g., `stopping_rule` or `eat_max`) to determine if messages should be 
 * suppressed. If the philosopher has died, it calls a specialized function 
 * to print the death message.
 * 
 * @param char *msg					The message describing the philosopher's 
 * 									current status.
 * @param t_philo *philo			A pointer to the philosopher's structure.
 * @param char *timestamp			A string representing the current 
 * 									timestamp.
 * 
 * @return void
 * 
 * The function "ft_strcmp" compares two strings lexicographically.
 * It returns the difference between the first differing characters in 
 * the two strings or 0 if the strings are equal.
 * 
 * @param const char *s1			The first string to compare.
 * @param const char *s2			The second string to compare.
 * 
 * @return int						Returns 0 if the strings are equal, a 
 * 									positive value if s1 is greater, or a 
 * 									negative value if s1 is less.
 * 
 */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_print_message(char *msg, t_philo *philo, char *timestamp)
{
	int	stopping_rule_flag;
	int	eat_max_flag;

	if (ft_strcmp(msg, DIED) == 0)
	{
		free(timestamp);
		return (ft_print_dead(philo, msg, philo->envp));
	}
	pthread_mutex_lock(&philo->envp->writing);
	philo->envp->last_time_status = ft_philo_atoi(timestamp);
	pthread_mutex_unlock(&philo->envp->writing);
	pthread_mutex_lock(&philo->envp->stopping_mutex);
	stopping_rule_flag = philo->envp->stopping_rule;
	pthread_mutex_unlock(&philo->envp->stopping_mutex);
	pthread_mutex_lock(&philo->envp->mutex_eat_max);
	eat_max_flag = philo->envp->eat_max;
	pthread_mutex_unlock(&philo->envp->mutex_eat_max);
	pthread_mutex_lock(&philo->envp->writing);
	if (!stopping_rule_flag && !eat_max_flag)
		printf("%s\t" WHITE "%s " RESET "%s\n", timestamp, \
		philo->pos_char, msg);
}

void	ft_check_stamp(char *msg, t_philo *philo, int unlock)
{
	char	*timestamp;

	timestamp = ft_philo_itoa(ft_get_time() - philo->envp->init_time);
	if (!timestamp)
		return ;
	ft_print_message(msg, philo, timestamp);
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
