/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:16:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/15 00:30:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * 
 * 
 * 
 */

void	ft_terminate_philos(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		kill(envp->philos[i].pid, SIGKILL);
		i++;
	}
	while (wait(NULL) > 0)
		;
}

void ft_philosopher_life(t_philo *philo)
{
	t_envp *envp;

	envp = philo->envp;
	philo->last_meal = ft_get_time();

	while (!envp->stopping_rule)
	{
		ft_check_stamp("is thinking", philo, 1);
		ft_check_eat(philo);
		ft_check_stamp("is sleeping", philo, 1);
		ft_sleep(envp->time_to_sleep, envp);
	}
	sem_post(envp->meals_done);
}


// int	ft_create_philos(t_envp *envp)
// {
// 	int	i;

// 	i = 0;
// 	while (i < envp->nbr_philos)
// 	{
// 		envp->philos[i].pid = fork();
// 		if (envp->philos[i].pid == 0)
// 		{
// 			ft_philosopher_life(&envp->philos[i]);
// 			exit(EXIT_SUCCESS);
// 		}
// 		else if (envp->philos[i].pid < 0)
// 		{
// 			ft_manage_err_simple(FORK_ERR);
// 			return (EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }

int	ft_create_philos(t_envp *envp)
{
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		envp->philos[i].pid = fork();
		if (envp->philos[i].pid == 0)
		{
			ft_philosopher_life(&envp->philos[i]);
			exit(EXIT_SUCCESS);
		}
		else if (envp->philos[i].pid < 0)
		{
			perror("Fork error");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
