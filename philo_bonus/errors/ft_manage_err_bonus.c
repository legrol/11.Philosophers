/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:21:59 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/14 15:22:02 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_manage_err" displays an error message in a formatted 
 * manner using colored text and then terminates the program by calling 
 * `exit(EXIT_FAILURE)`.
 * 
 * @param const char *err			A string containing the error message 
 * 									to be displayed.
 * @return void
 * 
 * The function "ft_manage_err_simple" displays an error message in a 
 * formatted manner using colored text. Unlike "ft_manage_err", it does not 
 * terminate the program and is intended for logging or non-critical errors.
 * 
 * @param const char *err			A string containing the error message 
 * 									to be displayed.
 * @return void
 * 
 */

void	ft_manage_err(const char *err)
{
	printf(RED "Error: " RESET GREEN "%s\n" RESET, err);
	exit (EXIT_FAILURE);
}

void	ft_manage_err_simple(const char *err)
{
	printf(RED "Error: " RESET YELLOW "%s\n" RESET, err);
}
