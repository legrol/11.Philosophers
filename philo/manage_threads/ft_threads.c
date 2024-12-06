/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:38:24 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/08 00:14:35 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "" xxx
 * 
 * @param 			xxx
 * 
 */

static void	*myroutine(void *param)
{



}



int	ft_create_threads(t_envp	*envp)
{
	int	i;

	i = 0;
	envp->create_time = ft_get_time();
	while (i < envp->nbr_philos)
	{
		envp->philos[i].last_meal = ft_get_time();
		if (pthread_create(&(envp->philos[i].thread_id), NULL, \
		myroutine, &(envp->philos[i])))
			return (EXIT_FAILURE);
		i++;
	}
	ft_check_dead(envp, envp->philos);
//	desbloquear mutex
//	salir del hilo
	return (EXIT_SUCCESS);
}
