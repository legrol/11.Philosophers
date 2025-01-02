/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:44:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/30 17:25:08 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
// 	pos							position of the philo at the table.
//	times_eaten					number of times the philo has eaten.
//	right_fork					position of the right fork.
//	left_fork					position of the left fork.
//	last_meal					timestamp of the last meal in miliseconds.
//	pos_char					position char of the philo at table.
//	thread_id					id of the thread.
//	envp						pointer to the envp structure.
//  philo_mutex					XXXXXXXXXXXXXXXXXXXXXXXXXXX
//
// 	nbr_philos					number of philosophers in the simulation.
// 	time_to_die					max time without eating.
// 	time_to_eat					time that a philo takes to eat.
// 	time_to_sleep				time that a philo takes to sleep.
// 	time_to_think				time that a philo takes to think.
// 	philo_eat_limit				maximum meal limit for each philo.
// 	eat_max						max eats of each philo.
// 	stopping_rule				flag indicating whether the sim should stop.
// 	init_time					timestamp when the sim starts in miliseconds.
// 	philos						array of philos structures.
// 	forks						array of mutexes to represent the forks.	
// 	mealtime					mutex to control the time of the meals.
// 	writing						mutex to print the status of the philos.
// ............................................................................

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
	pthread_mutex_t	philo_mutex;
}					t_philo;

typedef struct s_envp
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				philo_eat_limit;
	int				eat_max;
	int				stopping_rule;
	unsigned long	init_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mealtime;
	pthread_mutex_t	writing;
	int				last_time_status;
	pthread_mutex_t	stopping_mutex;
	pthread_mutex_t	mutex_max_ate;
}					t_envp;

// ============================================================================
// Initialization
// ============================================================================
// int				ft_init_mutex(t_envp *envp);
// int				ft_init_sim(t_envp *envp);
// void			ft_init_struct(t_envp *envp, int argc, char *argv[]);
// int				ft_init_philo(t_envp *envp);

// ============================================================================
// Management errors
// ============================================================================
// void			ft_manage_err(const char *err);
// void			ft_manage_err_simple(const char *err);

// ============================================================================
// Management threads
// ============================================================================
int				ft_create_threads_and_monitor(t_envp *envp);

// ============================================================================
// Management philos
// ============================================================================
// void			ft_check_dead(t_envp *envp, t_philo *philo);
// void			ft_check_eat(t_philo *philo);
// void			ft_check_sleep(unsigned long total_time, t_envp *envp);
// void			ft_check_stamp(char *msg, t_philo *philo, int unlock);
// void			ft_check_think(unsigned long time, t_envp *envp);
// void			ft_finish_sim(t_envp *envp);

/// ============================================================================
// Utils functions
// ============================================================================
// int				ft_isinteger(char *nbr);
// unsigned long	ft_get_time(void);
// int				ft_philo_atoi(const char *str);
// char			*ft_philo_itoa(int n);
// void			ft_print_banner(void);

// INITIALIZATION STRUCTURES
void			ft_init_struct(t_envp *envp, int argc, char *argv[]);
int				ft_init_philos(t_envp *env);

// INITIALIZATION MUTEX

int				ft_init_philo_sim(t_envp *env);

// FREE
void			ft_free_philo(t_envp *data);

// UTILS
int				ft_atoi(const char *str);
unsigned int	ft_count_digits(int n);
char			*ft_itoa(int n);
void			ft_destroy_mutex(t_envp *data);

// CHECKER
int				ft_is_int(char *str);
int				ft_check_args(t_envp *env, int argc, char **argv);

// UTILS PHILOS
void			ft_sleep(unsigned long time, t_envp *data);
unsigned long	ft_get_time(void);
void			ft_dead(t_envp *data, t_philo *philo);
void			ft_check_status(char *mesg, t_philo *philo, \
int lock, t_envp *data);
void			ft_eat(t_philo *philo);
void			ft_think(unsigned long time, t_envp *data);

// UTILS THREADS
int				ft_lock_stop_flag(t_envp *data);
void			ft_check_dead_flag(t_philo *philo, t_envp *data);
void			ft_lock_mutex_ate(t_envp *data, int i);
void			ft_check_max_eat(t_envp *data, t_philo *philo);
void			ft_dead_util(t_philo *philo, t_envp *data, int i);
int				ft_ate_flag(t_envp *data);
void			ft_print_dead(t_philo *philo, char *mesg, t_envp *data);

// THREATS
int				ft_thread(t_envp *data);
int				ft_strcmp(const char *s1, const char *s2);

#endif
