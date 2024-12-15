/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:19:17 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/14 23:41:19 by rdel-olm         ###   ########.fr       */
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

static void	ft_monitor_philos(t_envp *envp)
{
	int	status;
	int	i;

	i = 0;
	while (i < envp->nbr_philos)
	{
		waitpid(-1, &status, 0); // Espera a cualquier hijo.
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			// Si algún filósofo muere, termina la simulación.
			i = 0;
			while (i < envp->nbr_philos)
				kill(envp->philos[i++].pid, SIGKILL);
			break ;
		}
		i++;
	}
}

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
// 	if (ft_check_params_recursive(&envp, argv, 1, argc))
// 		return (ft_manage_err_simple(BYE), EXIT_FAILURE);
// 	if (ft_init_sim(&envp))
// 		return (ft_manage_err_simple(INIT_ERR), EXIT_FAILURE);
// 	if (ft_create_philos(&envp))
// 	{
// 		ft_destroy_semaphores_and_free(&envp);
// 		return (ft_manage_err_simple(FORK_ERR), EXIT_FAILURE);
// 	}
// 	ft_check_dead(&envp, envp.philos);
// 	ft_terminate_philos(&envp);
// 	ft_destroy_semaphores_and_free(&envp);
// 	return (EXIT_SUCCESS);
// }

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
	if (ft_create_philos(&envp))
	{
		ft_destroy_semaphores_and_free(&envp);
		return (ft_manage_err_simple(FORK_ERR), EXIT_FAILURE);
	}
	ft_monitor_philos(&envp); // Monitorea desde el proceso principal.
	ft_destroy_semaphores_and_free(&envp);
	return (EXIT_SUCCESS);
}
