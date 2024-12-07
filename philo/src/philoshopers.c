/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoshopers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:43:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/07 17:47:04 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "main" xxx
 * 
 * @param int argc					xxx
 * @param char *argv[]				xxx
 * 
 * @return							xxx
 * 
 * The function "ft_check_params" xxx
 * 
 * @param t_envp *envp				xxx
 * @param int argc					xxx
 * @param char *argv[]				xxx
 * 
 * @return 							xxx
 * 
 */

static int	ft_check_params(t_envp *envp, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i++ < argc)
	{
		if (!ft_isinteger(argv[i]))
		{
			printf(RED ARG "%i" INVALID "\n" RESET, i);
			return (ft_manage_err_simple(NO_INT_ARGV_ERR), EXIT_FAILURE);
		}
		if (ft_philo_atoi(argv[i]) < 0)
		{
			printf(RED ARG "%i" NEGATIVE "\n" RESET, i);
			return (ft_manage_err_simple(INT_NEG_ARGV_ERR), EXIT_FAILURE);
		}
	}
	ft_init_struct(envp, argc, argv);
	if (envp->philo_eat_limit < 1 || envp->time_to_die < 1 || \
		envp->time_to_eat < 1 || envp->time_to_sleep < 1 || \
		envp->nbr_philos < 1)
	{
		printf(RED VALUES_INVALID "\n" RESET);
		return (ft_manage_err_simple(PARAMS_ERR), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_envp	envp;

	envp.eat_max = 0;
	envp.stopping_rule = 0;
	if (argc < 5 || argv > 6)
		return (ft_manage_err_simple(USAGE_ERR), EXIT_FAILURE);
	if (ft_check_params(&envp, argc, argv))
		return ("Bye, my friend.", EXIT_FAILURE);
	if (!ft_init_sim(&envp)) // desarrollar
		return (ft_manage_err_simple(INIT_ERR), EXIT_FAILURE);
	if (!ft_create_threads(&envp)) // desarrollar
		return (ft_manage_err_simple(THREADS_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
