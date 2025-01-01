
void	ft_check_sleep(unsigned long total_time, t_envp *envp)
{
	unsigned long	init;

	init = ft_get_time();
	while (1)
	{
		pthread_mutex_lock(&envp->writing);
		if (envp->stopping_rule)
		{
			pthread_mutex_unlock(&envp->writing);
			break ;
		}
		pthread_mutex_unlock(&envp->writing);
		if (ft_get_time() - init >= total_time)
			break ;
		usleep(30);
	}
	return ;
}

void	ft_check_think(unsigned long time, t_envp *envp)
{
	ft_check_sleep(time, envp);
}

void	ft_check_dead(t_envp *envp, t_philo *philo)
{
	int	i;
	int	eaten_count;

	while (1)
	{
		i = 0;
		while (i < envp->nbr_philos)
		{
			pthread_mutex_lock(&philo[i].philo_mutex);
			if ((int)(ft_get_time() - philo[i].last_meal) >= envp->time_to_die)
			{
				ft_check_stamp(RED DIED RESET "\n", &philo[i], UNLOCK);
				pthread_mutex_lock(&envp->writing);
				envp->stopping_rule = 1;
				pthread_mutex_unlock(&envp->writing);
				pthread_mutex_unlock(&philo[i].philo_mutex);
				return ;
			}
			pthread_mutex_unlock(&philo[i].philo_mutex);
			i++;
		}
		pthread_mutex_lock(&envp->writing);
		if (envp->stopping_rule || envp->eat_max)
		{
			pthread_mutex_unlock(&envp->writing);
			break ;
		}
		pthread_mutex_unlock(&envp->writing);
		eaten_count = 0;
		i = 0;
		while (envp->philo_eat_limit && i < envp->nbr_philos)
		{
			pthread_mutex_lock(&philo[i].philo_mutex);
			if (philo[i].times_eaten >= envp->philo_eat_limit)
				eaten_count++;
			pthread_mutex_unlock(&philo[i].philo_mutex);
			i++;
		}
		pthread_mutex_lock(&envp->writing);
		envp->eat_max = (eaten_count == envp->nbr_philos);
		pthread_mutex_unlock(&envp->writing);
		if (envp->eat_max)
			break ;
	}
	ft_finish_sim(envp);
}

void	ft_check_eat(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	// if (philo->left_fork < philo->right_fork)
	// {
	// 	first_fork = philo->left_fork;
	// 	second_fork = philo->right_fork;
	// }
	// else
	// {
	// 	first_fork = philo->right_fork;
	// 	second_fork = philo->left_fork;
	// }

	if (philo->envp->nbr_philos == 1)
	{
		first_fork = philo->left_fork;
		// usleep(10);
		pthread_mutex_lock(&philo->envp->forks[first_fork]);
		ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
		pthread_mutex_unlock(&philo->envp->forks[first_fork]);
	}

	// pthread_mutex_lock(&philo->envp->forks[first_fork]);
	// ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);


	// pthread_mutex_lock(&philo->envp->forks[second_fork]);
	// ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
	// pthread_mutex_lock(&philo->philo_mutex);
	// ft_check_stamp(GREEN EAT RESET, philo, UNLOCK);
	// philo->last_meal = ft_get_time();
	// philo->times_eaten++;
	// pthread_mutex_unlock(&philo->philo_mutex);
	// ft_check_sleep(philo->envp->time_to_eat, philo->envp);
	// pthread_mutex_unlock(&philo->envp->forks[second_fork]);
	// pthread_mutex_unlock(&philo->envp->forks[first_fork]);

	// Intentar bloquear el segundo tenedor si hay más de un filósofo

	if (philo->envp->nbr_philos > 1)
	{
		if (philo->left_fork < philo->right_fork)
		{
			first_fork = philo->left_fork;
			second_fork = philo->right_fork;
		}
		else
		{
			first_fork = philo->right_fork;
			second_fork = philo->left_fork;
		}
		usleep(5);
		pthread_mutex_lock(&philo->envp->forks[first_fork]);
		ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
		pthread_mutex_lock(&philo->envp->forks[second_fork]);
		ft_check_stamp(BLUE TAKEN_FORK RESET, philo, UNLOCK);
		pthread_mutex_lock(&philo->philo_mutex);
		ft_check_stamp(GREEN EAT RESET, philo, UNLOCK);
		philo->last_meal = ft_get_time();
		philo->times_eaten++;
		pthread_mutex_unlock(&philo->philo_mutex);
		ft_check_sleep(philo->envp->time_to_eat, philo->envp);
		pthread_mutex_unlock(&philo->envp->forks[second_fork]);
		pthread_mutex_unlock(&philo->envp->forks[first_fork]);
	}

	// pthread_mutex_unlock(&philo->envp->forks[first_fork]);
}
