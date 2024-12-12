/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:43:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/10 22:00:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "main" serves as the entry point of the program. It validates 
 * the command-line arguments, initializes the environment structure, and 
 * starts the simulation if all parameters are valid.
 * 
 * @param int argc					The number of command-line arguments 
 * 									passed to the program.
 * @param char *argv[]				An array of strings containing the 
 * 									command-line arguments.
 * @return int						Returns EXIT_SUCCESS if the program 
 * 									executes successfully; otherwise, 
 * 									returns EXIT_FAILURE.
 * 
 * The function "ft_check_params" validates the command-line arguments to 
 * ensure they meet the requirements for the simulation. It checks if the 
 * arguments are integers, non-negative, and within valid ranges. If valid, 
 * it initializes the environment structure with these parameters.
 * 
 * @param t_envp *envp				A pointer to the environment structure 
 * 									that stores simulation parameters and 
 * 									state variables.
 * @param int argc					The number of command-line arguments 
 * 									provided to the program.
 * @param char *argv[]				An array of strings containing the 
 * 									command-line arguments.
 * @return int						Returns EXIT_SUCCESS if all parameters 
 * 									are valid; otherwise, returns EXIT_FAILURE.
 * 
 */

static int	ft_check_params(t_envp *envp, int argc, char *argv[])
{
	int	i;

	i = 1;
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
	if (envp->philo_eat_limit < 0 || envp->time_to_die < 0 || \
		envp->time_to_eat < 0 || envp->time_to_sleep < 0 || \
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
	if (ft_init_sim(&envp))
		return (ft_manage_err_simple(INIT_ERR), EXIT_FAILURE);
	if (ft_create_threads(&envp))
		return (ft_manage_err_simple(THREADS_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
