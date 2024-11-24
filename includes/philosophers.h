/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:44:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/11/24 20:46:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ============================================================================
// Libraries
// ============================================================================
# include <unistd.h>			// for write...
# include <stdlib.h>			// for typedef, malloc...
# include <math.h>				// for PI, etc.
# include <fcntl.h>				// for open, O_RDONLY, etc.
# include <stdio.h>				// for printf...
# include <stdbool.h>			// for booleans...
# include <signal.h>			// for SIGINT, SIGQUIT...
# include <readline/readline.h> // for readline...
# include <readline/history.h>	// for clear_history...
# include <sys/wait.h> 			// for wait, waitpid, WIFSIGNALED(status)...
# include <string.h>			// for strchr, strcpy, etc.
# include <termios.h>			// for terminal I/O interfaces.

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
// typedef enum e_tok_typ_enum
// {
// 	TOKEN_EMPTY,
// 	TOKEN_REDIR_STDIN,
// 	TOKEN_REDIR_STDOUT,
// 	TOKEN_REDIR_APPEND,
// 	TOKEN_REDIR_HEREDOC,
// 	TOKEN_COMMAND,
// 	TOKEN_OPTION,
// 	TOKEN_ARG,
// 	TOKEN_PIPE,
// }					t_tok_typ_enum;

// typedef struct s_minishell
// {
// 	char			**envp;
// 	t_envp			*list_envp;
// 	int				stdin;
// 	int				stdout;
// 	char			*line;
// 	t_token			*tokens;
// 	int				exit;
// 	char			*dirprompt;
// }					t_minishell;

// ============================================================================
// Management errors
// ============================================================================
void		ft_manage_err(const char *err);

// ============================================================================
// Release funtions
// ============================================================================


// ============================================================================
// Initialization functions
// ============================================================================


// ============================================================================
// Utils functions
// ============================================================================



#endif
