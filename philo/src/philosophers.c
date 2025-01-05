/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:43:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 19:20:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The "main" function initializes and starts the philosopher simulation. It 
 * validates the input arguments, handles the special case of one philosopher, 
 * initializes the simulation environment, and manages the simulation threads.
 * 
 * @param int argc					The number of command-line arguments.
 * @param char *argv[]				The command-line arguments containing 
 * 									the simulation parameters.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									executes successfully. Returns EXIT_FAILURE 
 * 									if any error occurs during initialization 
 * 									or execution.
 * 
 * The function "ft_check_params" validates the command-line arguments provided 
 * to the simulation. It ensures that each argument is an integer, 
 * non-negative, and initializes the simulation parameters if valid.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									where the parameters will be stored.
 * @param int argc					The number of command-line arguments.
 * @param char *argv[]				The command-line arguments containing 
 * 									the simulation parameters.
 * 
 * @return int						Returns EXIT_SUCCESS if all parameters 
 * 									are valid. Returns EXIT_FAILURE and prints 
 * 									an error message if any parameter is 
 * 									invalid.
 * 
 * The function "ft_check_params_aux" validates the philosopher simulation 
 * parameters stored in the `envp` structure. It ensures that the number of 
 * philosophers, time limits, and eating limits meet the simulation's 
 * constraints.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									containing the simulation parameters.
 * 
 * @return int						Returns EXIT_SUCCESS if all parameters 
 * 									are valid. Returns EXIT_FAILURE and prints 
 * 									an error message if any parameter is 
 * 									invalid.
 * 
 */

static int	ft_check_params_aux(t_envp *envp)
{
	if (envp->nbr_philos < 1)
	{
		printf(RED VALUES_INVALID "\n" RESET);
		return (ft_manage_err_simple(PARAMS_ERR_0), EXIT_FAILURE);
	}
	if (envp->nbr_philos > 200)
	{
		printf(RED VALUES_INVALID "\n" RESET);
		return (ft_manage_err_simple(PARAMS_ERR_1), EXIT_FAILURE);
	}
	if (envp->time_to_die < 60 || envp->time_to_eat < 60 || \
	envp->time_to_sleep < 60)
	{
		printf(RED VALUES_INVALID "\n" RESET);
		return (ft_manage_err_simple(PARAMS_ERR_2), EXIT_FAILURE);
	}
	if (envp->philo_eat_limit < 0 || envp->time_to_die < 0 || envp->\
	time_to_eat < 0 || envp->time_to_sleep < 0)
	{
		printf(RED VALUES_INVALID "\n" RESET);
		return (ft_manage_err_simple(PARAMS_ERR_3), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_params(t_envp *envp, int argc, char *argv[])
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (i < argc)
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
		i++;
	}
	ft_init_struct(envp, argc, argv);
	check = ft_check_params_aux(envp);
	if (check == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
	if (ft_check_params(&envp, argc, argv))
		return (ft_manage_err_simple(BYE), EXIT_FAILURE);
	if (ft_philo_atoi(argv[1]) == 1)
		return (ft_manage_on_philo(&envp, argv));
	if (ft_init_sim(&envp))
		return (ft_manage_err_simple(INIT_ERR), EXIT_FAILURE);
	if (ft_create_threads_and_monitor(&envp))
		return (ft_manage_err_simple(THREADS_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
