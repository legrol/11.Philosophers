/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:19:17 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/19 21:11:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "main" serves as the entry point of the philosopher simulation. 
 * It validates command-line arguments, initializes the simulation environment, 
 * and starts the philosopher processes. It waits for the simulation to stop 
 * and performs cleanup before exiting.
 * 
 * @param int argc					The number of command-line arguments 
 * 									passed to the program.
 * @param char **argv				An array of strings containing the 
 * 									command-line arguments.
 * 
 * @return int						Returns EXIT_SUCCESS if the simulation runs 
 * 									and terminates successfully. Returns 
 * 									EXIT_FAILURE if any error occurs during 
 * 									initialization or execution.
 * 
 * The function "ft_check_params" validates the command-line arguments passed 
 * to the program. It ensures that all arguments are integers, non-negative, 
 * and within acceptable ranges. If validation passes, it initializes the 
 * simulation environment structure (`t_envp`) with the given arguments.
 * 
 * @param t_envp *env				A pointer to the simulation environment 
 * 									structure to be initialized.
 * @param int argc					The number of command-line arguments passed 
 * 									to the program.
 * @param char **argv				An array of strings containing the 
 * 									command-line arguments.
 * 
 * @return int						Returns EXIT_SUCCESS if all parameters are 
 * 									valid and initialization is successful. 
 * 									Returns EXIT_FAILURE otherwise.
 * 
 */

int	ft_check_params(t_envp *env, int argc, char **argv)
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
	ft_init_struct(argc, argv, env);
	if (env->nbr_philos < 1 || env->time_to_die < 0 || env->time_to_eat < 0
		|| env->time_to_sleep < 0)
	{
		printf(RED VALUES_INVALID "\n" RESET);
		return (ft_manage_err_simple(PARAMS_ERR), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_envp	env;
	t_philo	*philo;

	ft_print_banner();
	if (argc < 5 || argc > 6)
	{
		ft_manage_err_simple(NUM_ARGV_ERR);
		return (ft_manage_err_simple(USAGE_ERR), EXIT_FAILURE);
	}
	if (ft_check_params(&env, argc, argv))
		return (ft_manage_err_simple(BYE), EXIT_FAILURE);
	philo = ft_init_philo(&env);
	ft_init_sim(&env, philo);
	sem_wait(env.stop);
	ft_destroy_all(&env, philo);
	return (EXIT_SUCCESS);
}
