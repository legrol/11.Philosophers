/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:10:31 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/18 16:40:18 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

/**
 * The function "ft_init_philo" allocates and initializes an array of 
 * philosopher structures. Each philosopher is assigned an ID, an initial PID 
 * value of -1, a reference to the shared simulation data, and the initial eat
 * counter.
 * 
 * @param t_data *data				A pointer to the simulation data structure 
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
 * @param t_data *data				A pointer to the simulation data structure 
 * 									that contains shared data and semaphore 
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
 * @param t_data *data				A pointer to the simulation data structure 
 * 									that will store the semaphore references.
 * 
 * @return void
 * 
 * The function "ft_destroy_all" cleans up all resources used in the 
 * simulation. It kills all philosopher processes, closes all semaphores, and 
 * frees the memory allocated for the philosophers' array.
 * 
 * @param t_data *sim				A pointer to the simulation data structure 
 * 									that contains semaphore references and 
 * 									other shared simulation data.
 * @param t_philo *philo			A pointer to the array of philosopher 
 * 									structures representing each philosopher.
 * 
 * @return void
 * 
 */

void	ft_destroy_all(t_data *sim, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < sim->philo_count)
	{
		kill(philo[index].pid, SIGKILL);
		index++;
	}
	sem_close(sim->death);
	sem_close(sim->print);
	sem_close(sim->stop);
	sem_close(sim->forks);
	free(philo);
}

static void	ft_initialize_semaphores(t_data *data)
{
	sem_unlink("sem_death");
	sem_unlink("sem_print");
	sem_unlink("sem_forks");
	sem_unlink("sem_stop");
	data->death = sem_open("sem_death", O_CREAT, 0600, 1);
	data->print = sem_open("sem_print", O_CREAT, 0600, 1);
	data->forks = sem_open("sem_forks", O_CREAT, 0600, data->philo_count);
	data->stop = sem_open("sem_stop", O_CREAT, 0600, 1);
}

void	ft_init_sim(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	data->start = ft_get_time();
	data->philos = philo;
	ft_initialize_semaphores(data);
	sem_wait(data->stop);
	while (index < data->philo_count)
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

t_philo	*ft_init_philo(t_data *data)
{
	t_philo	*philo_array;
	int		index;

	index = 0;
	philo_array = malloc(sizeof(t_philo) * data->philo_count);
	if (!philo_array)
		return (NULL);
	while (index < data->philo_count)
	{
		philo_array[index].id = index;
		philo_array[index].pid = -1;
		philo_array[index].death = 0;
		philo_array[index].data = data;
		philo_array[index].eat_count = data->eat_counter;
		index++;
	}
	return (philo_array);
}
