/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:10:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/19 21:13:49 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_init_philo" allocates and initializes an array of 
 * philosopher structures. Each philosopher is assigned an ID, an initial PID 
 * value of -1, a reference to the shared simulation envp, and the initial eat
 * counter.
 * 
 * @param t_envp *envp				A pointer to the simulation envp structure 
 * 									that contains shared parameters and 
 * 									references.
 * 
 * @return t_philo*					A pointer to the dynamically allocated 
 * 									array of philosopher structures. Returns 
 * 									NULL if memory allocation fails.
 * 
 * The function "ft_init_sim" initializes the simulation by setting the start 
 * time, initializing semaphores, and forking processes for each philosopher.
 * Each philosopher process executes the `ft_routine` function.
 * 
 * @param t_envp *envp				A pointer to the simulation envp structure 
 * 									that contains shared daenvpta and semaphore 
 * 									references.
 * @param t_philo *philo			A pointer to the array of philosopher 
 * 									structures representing each philosopher.
 * 
 * @return void
 * 
 * The function "ft_initialize_semaphores" sets up the semaphores needed for 
 * the simulation. It unlinks any existing semaphores with the same names to 
 * ensure a clean start, and creates new ones with initial values based on 
 * their purpose (e.g., controlling access to forks).
 * 
 * @param t_envp *envp				A pointer to the simulation envp structure 
 * 									that will store the semaphore references.
 * 
 * @return void
 * 
 * The function "ft_destroy_all" cleans up all resources used in the 
 * simulation. It kills all philosopher processes, closes all semaphores, and 
 * frees the memory allocated for the philosophers' array.
 * 
 * @param t_envp *sim				A pointer to the simulation envp structure 
 * 									that contains semaphore references and 
 * 									other shared simulation envp.
 * @param t_philo *philo			A pointer to the array of philosopher 
 * 									structures representing each philosopher.
 * 
 * @return void
 * 
 */

void	ft_destroy_all(t_envp *sim, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < sim->nbr_philos)
	{
		kill(philo[index].pid, SIGKILL);
		index++;
	}
	sem_close(sim->death);
	sem_close(sim->write);
	sem_close(sim->stop);
	sem_close(sim->forks);
	free(philo);
}

static void	ft_initialize_semaphores(t_envp *envp)
{
	sem_unlink("sem_death");
	sem_unlink("sem_write");
	sem_unlink("sem_forks");
	sem_unlink("sem_stop");
	envp->death = sem_open("sem_death", O_CREAT, 0600, 1);
	envp->write = sem_open("sem_write", O_CREAT, 0600, 1);
	envp->forks = sem_open("sem_forks", O_CREAT, 0600, envp->nbr_philos);
	envp->stop = sem_open("sem_stop", O_CREAT, 0600, 1);
}

void	ft_init_sim(t_envp *envp, t_philo *philo)
{
	int	index;

	index = 0;
	envp->init_time = ft_get_time();
	envp->philos = philo;
	ft_initialize_semaphores(envp);
	sem_wait(envp->stop);
	while (index < envp->nbr_philos)
	{
		philo[index].pid = fork();
		if (philo[index].pid == 0)
		{
			ft_routine(&philo[index]);
			exit(EXIT_SUCCESS);
		}
		index++;
		usleep(100);
	}
}

t_philo	*ft_init_philo(t_envp *envp)
{
	t_philo	*philo_array;
	int		index;

	index = 0;
	philo_array = malloc(sizeof(t_philo) * envp->nbr_philos);
	if (!philo_array)
		return (NULL);
	while (index < envp->nbr_philos)
	{
		philo_array[index].pos = index;
		philo_array[index].pid = -1;
		philo_array[index].death = 0;
		philo_array[index].envp = envp;
		philo_array[index].eat_count = envp->eat_counter;
		index++;
	}
	return (philo_array);
}
