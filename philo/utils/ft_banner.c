/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_banner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:55:57 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/10 23:16:59 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * The function "ft_print_banner" generates the project start banner. 
 * 
 */

// void	ft_print_banner(void)
// {
// 	printf(RED"    ____  __    _ __                       __                  \
// 	 "RESET);
// 	printf(RED"   / __ \\/ /_  (_) /___  _________  ____  / /_  ___  __________\
// 	 "RESET);
// 	printf(YELLOW"  / /_/ / __ \\/ / / __ \\/ ___/ __ \\/ __ \\/ __ \\/ _ \\/ \
// 	___/ ___/ "RESET);
// 	printf(YELLOW" / ____/ / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__ \
// 	 )  "RESET);
// 	printf(RED"/_/   /_/ /_/_/_/\\____/____/\\____/ .___/_/ /_/\\___/_/  /____\
// 	/  "RESET);
// 	printf(RED"                                /_/                            \
// 	 "RESET);
// 	printf("                                                                ");
// }

void	ft_print_banner(void)
{
	printf(RED"    ____  __    _ __                       __                 \
	  \n"RESET);
	printf(RED"   / __ `/ /_  (_) /___  _________  ____  / /_  ___  __________ \
	\n"RESET);
	printf(YELLOW"  / /_/ / __ `/ / / __ `/ ___/ __ `/ __ '/ __ `/ _ `/ ___/ ___/\
	 \n"RESET);
	printf(YELLOW" / ____/ / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  )\
	  \n"RESET);
	printf(RED"/_/   /_/ /_/_/_/`____/____/`____/ .___/_/ /_/`___/_/  /____/  \
	 \n"RESET);
	printf(RED"                                /_/                            \
	 \n"RESET);
	printf("                                                               \
	 \n"RESET);
}
