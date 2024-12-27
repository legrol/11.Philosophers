/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:13:04 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/27 12:32:42 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The function "ft_manage_err_simple" displays an error message in a 
 * formatted manner using colored text. Unlike "ft_manage_err", it does not 
 * terminate the program and is intended for logging or non-critical errors.
 * 
 * @param const char *err			A string containing the error message 
 * 									to be displayed.
 * @return void
 * 
 */

void	ft_manage_err_simple(const char *err)
{
	printf(RED "Error: " RESET YELLOW "%s\n" RESET, err);
}
