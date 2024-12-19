/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:44:36 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/19 19:44:50 by rdel-olm         ###   ########.fr       */
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
# include <fcntl.h>				// for O_CREAT and others constants...
# include <string.h>			// for memcpy...              			
# include <sys/stat.h>			// for S_IRUSR, S_IWUSR, S_IXUSR, etc...
# include <limits.h>			// for INT_MAX, MIN_INT...
# include <sys/wait.h>			// for wait...

// ============================================================================
// Access to my libraries
// ============================================================================
# include "colors_bonus.h"
# include "ft_macros_bonus.h"

// ============================================================================
// Forward declarations
// ============================================================================
typedef struct s_philo	t_philo;

// ============================================================================
// Structures
// ============================================================================
// 	pos							position of the philo at table.
//	death						flag to indicate if the philosopher has died.
//  eat_count					number of times the philo has eaten.
//	last_meal					timestamp of the last meal in miliseconds.
//  next_meal					deadline for the next meal to avoid starvation.
//	pid							process id of the philosopher process.
//	envp						pointer to the envp structure.
//
// 	nbr_philos					number of philosophers in the simulation.
// 	time_to_die					max time without eating.
// 	time_to_eat					time that a philo takes to eat.
// 	time_to_sleep				time that a philo takes to sleep.
//	eat_counter					counter for number of meals by all philos.
// 	philo_eat_limit				maximum meal limit for each philo.
// 	current_eat					current count of philos who reached max meals.
// 	start						timestamp when the sim starts in miliseconds.
// 	forks						semaphore array to represent the forks.
// 	writing						semaphore for writing to the console.
//  death						semaphore to manage philo death conditions.
//	stop						semaphore to signal stopping the simulation.
// 	philos						array of philos structures.
// ............................................................................
typedef struct s_philo
{
	int				id;  			// pos CAMBIAR
	int				death;			// ok
	int				eat_count;		// ok
	unsigned int	last_meal;		// ok
	unsigned int	next_meal;		// ok
	pid_t			pid;			// ok
	struct s_data	*data;			// t_envp envp CAMBIAR
}					t_philo;

typedef struct s_data
{
	int				philo_count;	// nbr_philos CAMBIAR
	int				time_to_die;	// ok
	int				time_to_eat;	// ok
	int				time_to_sleep;	// ok
	int				eat_counter;	// ok
	int				max_eat;		// philo_eat_limit CAMBIAR 
	int				current_eat;	// ok
	unsigned long	start;			// init_time CAMBIAR
	sem_t			*forks;			// ok
	sem_t			*print;			// write CAMBIAR
	sem_t			*death;			// ok
	sem_t			*stop;			// ok
	t_philo			*philos;		// ok
}					t_data;			// t_envp CAMBIAR

// ============================================================================
// Management errors
// ============================================================================
void			ft_manage_err(const char *err);
void			ft_manage_err_simple(const char *err);

// ============================================================================
// Main functions
// ============================================================================
int				ft_check_params(t_data *env, int argc, char **argv);

// ============================================================================
// Initialization functions
// ============================================================================
void			ft_destroy_all(t_data *simulation, t_philo *philo);
int				ft_init_struct(int argc, char **argv, t_data *env);
t_philo			*ft_init_philo(t_data *data);
void			ft_init_sim(t_data *data, t_philo *philo);

// ============================================================================
// Management philos
// ============================================================================
void			*ft_check_death(void *arg);
void			ft_check_eat(t_philo *philo);
void			ft_check_sleep(t_philo *philo);
void			ft_check_think(t_philo *philo);
void			ft_manage_fork(t_philo *philo);
void			ft_routine(t_philo *philo);

// ============================================================================
// Utils 
// ============================================================================
unsigned int	ft_get_time(void);
int				ft_isinteger(char *nptr);
void			ft_log_status(char *id, t_philo *philo);
int				ft_philo_atoi(const char *str);
void			ft_print_banner(void);
int				ft_strcmp(const char *s1, const char *s2);

#endif
