/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:44:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/10 22:55:43 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// ============================================================================
// Libraries
// ============================================================================
# include <unistd.h>			// for write...
# include <stdlib.h>			// for typedef, malloc...
# include <stdio.h>				// for printf...
# include <sys/time.h>			// for time functions...
# include <pthread.h>			// for thread management functions...

// ============================================================================
// Access to my libraries
// ============================================================================
# include "colors.h"
# include "ft_macros.h"

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
	int				right_fork;
	int				left_fork;
	unsigned long	last_meal;
	char			*pos_char;
	pthread_t		thread_id;
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	mealtime;
	pthread_mutex_t	writing;
}					t_envp;

// ============================================================================
// Initialization
// ============================================================================
void			ft_init_struct(t_envp *envp, int argc, char *argv[]);
int				ft_init_sim(t_envp *envp);
int				ft_init_mutex(t_envp *envp);
int				ft_init_philo(t_envp *envp);

// ============================================================================
// Management errors
// ============================================================================
void			ft_manage_err(const char *err);
void			ft_manage_err_simple(const char *err);

// ============================================================================
// Management threads
// ============================================================================
int				ft_create_threads(t_envp	*envp);

// ============================================================================
// Management philos
// ============================================================================
void			ft_check_dead(t_envp *envp, t_philo *philo);
void			ft_check_eat(t_philo *philo);
void			ft_check_stamp(char *msg, t_philo *philo, int unlock);

/// ============================================================================
// Utils functions
// ============================================================================
void			ft_print_banner(void);
int				ft_isinteger(char *nbr);
unsigned long	ft_get_time(void);
int				ft_philo_atoi(const char *str);
char			*ft_philo_itoa(int n);
void			ft_sleep(unsigned long total_time, t_envp *envp);

#endif
