/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:08:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/05 18:20:45 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define TAKEN_FORK			"has taken a fork"
# define THINK				"is thinking"
# define SLEEP				"is sleeping"
# define EAT				"is eating"
# define DIED				"died"
# define DONE				"The simulation has ended..."

# define USAGE_ERR			"❗Arguments: Usage: ./philo <Nbr philosophers> \
<time to die> <time to eat> <time to sleep> [Nbr times each philosopher must \
eat]"
# define NUM_ARGV_ERR		"❗1️⃣ Incorrect number of arguments, expected min 4\
 o max 5."
# define NUM_PHILO_ERR		"❗Invalid number of philosophers (1-200 allowed)."
# define NO_INT_ARGV_ERR	"❗Argument is not integer value"
# define INT_NEG_ARGV_ERR	"❗Argument with negativ integer value. Forbidden."
# define PARAMS_ERR_0		"❗Incorrect parameter number philo. Must be \
greater than 0."
# define PARAMS_ERR_1		"❗Incorrect parameter number philo. Must be less \
than 200."
# define PARAMS_ERR_2		"❗Incorrect parameteres. Must be greater than 60."
# define PARAMS_ERR_3		"❗Incorrect parameteres. Must be greater than 0."
# define ARG				"❗Argument "
# define INVALID			"❗is not valid."
# define NEGATIVE			"❗negative value."
# define VALUES_INVALID		"❗Values of some parameter are invalid."
# define INIT_ERR			"❗Initialization error."
# define THREADS_ERR		"❗Threads error."
# define BYE				"❗Fix the argument, my friend."
# define FORK_ERR			"❗Error: Fork failed. Could not create process."
# define PHILO_EATEN		" philosophers have eaten at least "
# define TIMES				"times."
# define POINTER_ERR		"❗Invalid pointer in philo_routine_one_philo."
# define LOCK_MUTEX_ERR		"❗Error: locking mutex."
# define UNLOCK_MUTEX_ERR	"❗Error: unlocking mutex."
# define INIT_MUTEX_ERR		"❗Error: initializing mutex."
# define ALLOC_POSCH_ERR	"❗Error: allocating pos_char."
# define CREAT_THREAD_ERR	"❗Error: creating thread."

# define INT_MAX			2147483647
# define INT_MIN			-2147483648
# define UNLOCK				1
# define LOCK				0
# define MAX_PHILOS			200
# define MS_CONVERSION		1000

#endif
