/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:44:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/05 18:21:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ============================================================================
// Libraries
// ============================================================================
# include <unistd.h>			// for write...
# include <stdlib.h>			// for typedef, malloc...
// # include <math.h>			// for PI, etc.
// # include <fcntl.h>			// for open, O_RDONLY, etc.
# include <stdio.h>				// for printf...
// # include <stdbool.h>		// for booleans...
// # include <signal.h>			// for SIGINT, SIGQUIT...
// # include <readline/readline.h>  // for readline...
// # include <readline/history.h>	// for clear_history...
// # include <sys/wait.h> 			// for wait, waitpid, WIFSIGNALED(status)...
// # include <string.h>			// for strchr, strcpy, etc.
// # include <termios.h>		// for terminal I/O interfaces.
# include <sys/time.h>			// for time functions...
# include <pthread.h>			// for thread management functions...

// ============================================================================
// Access to my libraries
// ============================================================================
# include "colors.h"
# include "examft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "get_next_line.h"
# include "libft.h"
# include "ft_macros.h"

// ============================================================================
// Structures
// ============================================================================
typedef struct s_envp
{
	int				total_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count_max;
	t_philo			*philos;
}					t_envp;

typedef struct s_philo
{
	int				pos;
	t_envp			*envp;
}					t_philo;

// ============================================================================
// Initialization
// ============================================================================
void		ft_init_struct(t_envp *envp, int argc, char *argv[]);

// ============================================================================
// Management errors
// ============================================================================
void		ft_manage_err(const char *err);

/// ============================================================================
// Utils functions
// ============================================================================
int			ft_isint(char *nbr);

#endif
