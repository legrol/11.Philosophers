/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:43:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 21:28:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "main" serves as the entry point of the philosopher simulation. 
 * It validates command-line arguments, initializes the simulation environment, 
 * starts the simulation, and monitors its execution. 
 * 
 * @param int argc					The number of command-line arguments passed 
 * 									to the program.
 * @param char *argv[]				An array of strings containing the 
 * 									command-line arguments.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation 
 * 									executes successfully. Returns EXIT_FAILURE 
 * 									if any error occurs during initialization 
 * 									or execution.
 * 
 * The function "ft_check_params" validates all command-line arguments and 
 * initializes the simulation environment structure (`t_envp`). It ensures 
 * that all arguments are valid and checks additional constraints on the 
 * simulation parameters.
 * 
 * @param t_envp *envp				A pointer to the simulation environment 
 * 									structure to be initialized.
 * @param int argc					The number of command-line arguments.
 * @param char *argv[]				An array of command-line arguments.
 * 
 * @return int						Returns EXIT_SUCCESS if all arguments are 
 * 									valid and initialization is successful. 
 * 									Returns EXIT_FAILURE otherwise.
 * 
 * The function "ft_validate_argument" validates an individual command-line 
 * argument. It ensures that the argument is an integer, non-negative, and 
 * within specific constraints (e.g., the number of philosophers must be 
 * between 1 and 200). 
 * 
 * @param char *arg					The command-line argument to validate.
 * @param int index					The position of the argument in the input 
 * 									array (used for error messages).
 * 
 * @return int						Returns EXIT_SUCCESS if the argument is 
 * 									valid. Returns EXIT_FAILURE otherwise.
 *  
 */

static int	ft_validate_argument(char *arg, int index)
{
	int	arg_value;

	if (!ft_isinteger(arg))
	{
		printf(RED ARG "%i" INVALID RESET "\n", index);
		return (ft_manage_err_simple(NO_INT_ARGV_ERR), EXIT_FAILURE);
	}
	arg_value = ft_philo_atoi(arg);
	if (arg_value < 0)
	{
		printf(RED ARG "%i" NEGATIVE RESET "\n", index);
		return (ft_manage_err_simple(INT_NEG_ARGV_ERR), EXIT_FAILURE);
	}
	if (index == 1 && (arg_value < 1 || arg_value > MAX_PHILOS))
	{
		printf(RED ARG "%i" INVALID RESET "\n", index);
		return (ft_manage_err_simple(NUM_PHILO_ERR), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_params(t_envp *envp, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_validate_argument(argv[i], i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	ft_init_struct(envp, argc, argv);
	if (envp->philo_eat_limit < 0 || envp->time_to_die <= 0 \
	|| envp->time_to_eat <= 0 || envp->time_to_sleep <= 0 \
	|| envp->nbr_philos < 1)
	{
		printf(RED VALUES_INVALID RESET "\n");
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
	if (ft_create_threads_and_monitor(&envp))
		return (ft_manage_err_simple(THREADS_ERR), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
