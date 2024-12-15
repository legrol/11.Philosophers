/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:44:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/15 00:19:34 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// ============================================================================
// Libraries
// ============================================================================
# include <unistd.h>			// for write...
# include <stdlib.h>			// for typedef, malloc...
# include <stdio.h>				// for printf...
# include <sys/time.h>			// for time functions...
# include <pthread.h>			// for thread management functions...
# include <semaphore.h>			// for semaphore management functions...
# include <signal.h>			// for SIGKILL, pid...
# include <sys/wait.h>			// fot wait...
# include <fcntl.h>				// for O_CREAT and others constants...

// ============================================================================
// Access to my libraries
// ============================================================================
# include "colors_bonus.h"
# include "ft_macros_bonus.h"

// ============================================================================
// Forward declarations
// ============================================================================
struct	s_envp;

// ============================================================================
// Structures
// ============================================================================
typedef struct s_philo
{
	int				pos;
	int				times_eaten;
	unsigned long	last_meal;
	char			*pos_char;
	pid_t			pid;
	struct s_envp	*envp;
}					t_philo;

typedef struct s_envp
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_eat_limit;
	int				eat_max;
	int				stopping_rule;
	unsigned long	init_time;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*mealtime;
	sem_t			writing;
	sem_t			*meals_done;
}					t_envp;

// ============================================================================
// Initialization bonus
// ============================================================================
int				ft_init_semaphores(t_envp *envp);
int				ft_init_sim(t_envp *envp);
void			ft_init_struct(t_envp *envp, int argc, char *argv[]);
int				ft_init_philo(t_envp *envp);

// ============================================================================
// Management errors bonus
// ============================================================================
void			ft_manage_err(const char *err);
void			ft_manage_err_simple(const char *err);

// ============================================================================
// Management 
// ============================================================================

// ============================================================================
// Management philos bonus
// ============================================================================
void			ft_check_dead(t_envp *envp, t_philo *philo);
void			ft_check_eat(t_philo *philo);
void			ft_check_stamp(char *msg, t_philo *philo, int unlock);
int				ft_create_philos(t_envp *envp);
void			ft_destroy_semaphores_and_free(t_envp *envp);
void			ft_terminate_philos(t_envp *envp);

/// ============================================================================
// Utils functions
// ============================================================================
int				ft_isinteger(char *nbr);
unsigned long	ft_get_time(void);
int				ft_philo_atoi(const char *str);
char			*ft_philo_itoa(int n);
void			ft_print_banner(void);
void			ft_sleep(unsigned long total_time, t_envp *envp);

#endif
