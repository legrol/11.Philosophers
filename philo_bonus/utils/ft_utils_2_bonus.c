/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:12:19 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/18 19:08:47 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_log_status" logs the philosopher's current action (e.g., 
 * eating, sleeping, thinking, or dying). It calculates the relative timestamp 
 * since the simulation started and ensures thread-safe access to the logging 
 * process using semaphores.
 * 
 * @param char *id					A string representing the action being 
 * 									logged.
 * @param t_philo *philo			A pointer to the philosopher's structure 
 * 									representing their state.
 * 
 * The function "ft_log_status_aux" logs a philosopher's action (e.g., taking 
 * a fork, eating, sleeping, thinking, or dying) with a formatted timestamp 
 * and color-coded messages for better readability.
 * 
 * @param unsigned int timestamp	The timestamp of the action relative to 
 * 									the simulation start.
 * @param int philo_pos				The position (ID) of the philosopher.
 * @param char *id					A string representing the action being 
 * 									logged.
 * 
 * @return void
 * 
 * The function "ft_get_time" retrieves the current time in milliseconds 
 * since the Unix epoch (January 1, 1970). It uses `gettimeofday` to fetch 
 * the time in seconds and microseconds, then converts it to milliseconds.
 * 
 * @return unsigned int				Returns the current time in milliseconds.
 * 
 * The function "ft_isinteger" checks if a given string represents a valid 
 * non-negative integer. If valid, it converts the string to its integer value.
 * 
 * @param char *arg					A string to be checked and converted.
 * 
 * @return int						Returns the integer value if the string is 
 * 									valid. Returns -1 if the string contains 
 * 									non-numeric characters.
 * 
 */

int	ft_isinteger(char *arg)
{
	int	index;
	int	nbr;

	index = 0;
	nbr = 0;
	while (arg[index])
	{
		if (arg[index] >= '0' && arg[index] <= '9')
			nbr = nbr * 10 + (arg[index] - '0');
		else
			return (-1);
		index++;
	}
	return (nbr);
}

unsigned int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

static void	ft_log_status_aux(unsigned int timestamp, int philo_pos, char *id)
{
	if (!ft_strcmp(id, TAKEN_FORK))
		printf("%u\t" WHITE "%d " RESET BLUE "%s" RESET "\n", timestamp, \
		philo_pos, TAKEN_FORK);
	else if (!ft_strcmp(id, EAT))
		printf("%u\t" WHITE "%d " RESET GREEN "%s" RESET "\n", timestamp, \
		philo_pos, EAT);
	else if (!ft_strcmp(id, SLEEP))
		printf("%u\t" WHITE "%d " RESET ORANGE "%s" RESET "\n", timestamp, \
		philo_pos, SLEEP);
	else if (!ft_strcmp(id, THINK))
		printf("%u\t" WHITE "%d " RESET YELLOW "%s" RESET "\n", timestamp, \
		philo_pos, THINK);
	else if (!ft_strcmp(id, DEAD))
		printf("%u\t" WHITE "%d " RESET RED "%s" RESET "\n\n", timestamp, \
		philo_pos, DEAD);
}

void	ft_log_status(char *id, t_philo *philo)
{
	unsigned int	timestamp;
	int				philo_pos;

	timestamp = ft_get_time() - philo->data->start;
	philo_pos = philo->id + 1;
	sem_wait(philo->data->print);
	if (!ft_strcmp(id, DONE))
	{
		printf("\n%s\n", DONE);
		printf(GREEN "%d" RESET PHILO_EATEN GREEN "%d " RESET TIMES "\n\n",
			philo->data->philo_count, philo->data->max_eat);
	}
	else
		ft_log_status_aux(timestamp, philo_pos, id);
	if (ft_strcmp(id, DEAD) != 0)
		sem_post(philo->data->print);
}
