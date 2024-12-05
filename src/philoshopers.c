/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoshopers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:43:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/04 20:12:13 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "main" xxx
 * 
 * @param int argc					xxx
 * @param char *argv[]				xxx
 * 
 */

static void	ft_check_params(t_envp *envp, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
		{
			ft_printf(RED"Argument %i is not valid\n"RESET, i);
			ft_manage_err(GREEN NO_INT_ARGV_ERR RESET);
		}
		if (ft_atoi(argv[i]) < 0)
		{
			ft_printf(RED"Argument %i negative value\n"RESET, i);
			ft_manage_err(GREEN INT_NEG_ARGV_ERR RESET);
		}
		i++;
	}
	ft_init_envp(envp, argc, argv);
	if (envp->eat_count_max < 1 || envp->time_to_die < 1 || \
		envp->time_to_eat < 1 || envp->time_to_sleep < 1 || \
		envp->total_philo < 1)
	{
		ft_printf(RED"The values ​​of some parameter are invalid\n"RESET);
		ft_manage_err(GREEN PARAMS_ERR RESET);
	}
}

int	main(int argc, char *argv[])
{
	t_envp	envp;

	if (argc < 5 || argv > 6)
		ft_manage_err(USAGE_ERR);
	ft_check_params(&envp, argc, argv);



	return (0);
}
