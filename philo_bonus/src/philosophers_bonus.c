/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:19:17 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/14 15:09:23 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "main" xxx
 * 
 * @param int argc					xxx
 * @param char *argv[]				xxx
 * 
 */

// static int	ft_check_params(t_envp *envp, int argc, char *argv[])
// {
// 	int	i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!ft_isinteger(argv[i]))
// 		{
// 			printf(RED ARG "%i" INVALID "\n" RESET, i);
// 			return (ft_manage_err_simple(NO_INT_ARGV_ERR), EXIT_FAILURE);
// 		}
// 		if (ft_philo_atoi(argv[i]) < 0)
// 		{
// 			printf(RED ARG "%i" NEGATIVE "\n" RESET, i);
// 			return (ft_manage_err_simple(INT_NEG_ARGV_ERR), EXIT_FAILURE);
// 		}
// 		i++;
// 	}
// 	ft_init_struct(envp, argc, argv);
// 	if (envp->philo_eat_limit < 0 || envp->time_to_die < 0 || envp->\
// 	time_to_eat < 0 || envp->time_to_sleep < 0 || envp->nbr_philos < 1)
// 	{
// 		printf(RED VALUES_INVALID "\n" RESET);
// 		return (ft_manage_err_simple(PARAMS_ERR), EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

// int	main(int argc, char *argv[])
// {
// 	t_envp	envp;

// 	ft_print_banner();
// 	envp.eat_max = 0;
// 	envp.stopping_rule = 0;
// 	if (argc < 5 || argc > 6)
// 	{
// 		ft_manage_err_simple(NUM_ARGV_ERR);
// 		return (ft_manage_err_simple(USAGE_ERR), EXIT_FAILURE);
// 	}
// 	if (ft_check_params(&envp, argc, argv))
// 		return (ft_manage_err_simple(BYE), EXIT_FAILURE);
// 	if (ft_init_sim(&envp))
// 		return (ft_manage_err_simple(INIT_ERR), EXIT_FAILURE);
// 	if (ft_create_threads_and_monitor(&envp))
// 		return (ft_manage_err_simple(THREADS_ERR), EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

int	ft_check_params_recursive(t_envp *envp, char *argv[], int index, int argc)
{
	if (index >= argc)
	{
		ft_init_struct(envp, argc, argv);
		if (envp->philo_eat_limit < 0 || envp->time_to_die < 0 || \
		envp->time_to_eat < 0 || envp->time_to_sleep < 0 || \
		envp->nbr_philos < 1)
		{
			printf(RED VALUES_INVALID "\n" RESET);
			return (ft_manage_err_simple(PARAMS_ERR), EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	if (!ft_isinteger(argv[index]))
	{
		printf(RED ARG "%i" INVALID "\n" RESET, index);
		return (ft_manage_err_simple(NO_INT_ARGV_ERR), EXIT_FAILURE);
	}
	if (ft_philo_atoi(argv[index]) < 0)
	{
		printf(RED ARG "%i" NEGATIVE "\n" RESET, index);
		return (ft_manage_err_simple(INT_NEG_ARGV_ERR), EXIT_FAILURE);
	}
	return (ft_check_params_recursive(envp, argv, index + 1, argc));
}

int	main(int argc, char *argv[])
{
	t_envp	envp;

	ft_print_banner();
	envp.eat_max = 0;
	envp.stopping_rule = 0;
	if (argc < 5 || argc > 6)
	{
		ft_manage_err_simple(NUM_ARGV_ERR);
		return (ft_manage_err_simple(USAGE_ERR), EXIT_FAILURE);
	}
	if (ft_check_params_recursive(&envp, argv, 1, argc))
		return (ft_manage_err_simple(BYE), EXIT_FAILURE);
	if (ft_init_sim(&envp))
		return (ft_manage_err_simple(INIT_ERR), EXIT_FAILURE);
	ft_check_dead(&envp, envp.philos);
	ft_destroy_semaphores_and_free(&envp);
	return (EXIT_SUCCESS);
}
