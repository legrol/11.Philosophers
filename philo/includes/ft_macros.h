/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:08:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/09 21:32:01 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define USAGE_ERR			"❗Arguments: Usage: ./philo <Nbr philosophers> \
<time to die> <time to eat> <time to sleep> [Nbr times each philosopher must \
eat]"
# define NUM_ARGV_ERR		"❗1️⃣ Incorrect number of arguments, expected min 4\
 o max 5."
# define NO_INT_ARGV_ERR	"❗Argument is not integer value"
# define INT_NEG_ARGV_ERR	"❗Argument with negativ integer value. Forbidden."
# define PARAMS_ERR			"❗Incorrect parameteres."
# define ARG				"Argument "
# define INVALID			" is not valid."
# define NEGATIVE			" negative value."
# define VALUES_INVALID		"Values of some parameter are invalid."
# define INIT_ERR			"Initialization error."
# define THREADS_ERR		"Threads error."
# define BYE				"Fix the argument, my friend."

# define INT_MAX			2147483647
# define INT_MIN			-2147483648
# define UNLOCK				1
# define LOCK				0

#endif
