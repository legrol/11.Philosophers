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

static int	ft_check_params(t_env *env, int argc, char *argv[])
{



}

int	main(int argc, char *argv[])
{
	t_env	env;


	if (argc < 5 || argv > 6)
		ft_manage_err(USAGE_ERR);
	if (!ft_check_params(&env, argc, argv))
		ft_manage_err(NUM_ARGV_ERR);



	return (0);
}
