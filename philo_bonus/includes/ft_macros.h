/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:08:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/12/05 21:41:14 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define TAKEN_FORK			"has taken a fork"
# define THINK				"is thinking"
# define SLEEP				"is sleeping"
# define EAT				"is eating"
# define DIED				"died"

# define USAGE_ERR			"❗Arguments: Usage: ./philo <# philosophers> \
									<time to die> <time to eat> <time to \
									sleep> [# times each philosopher must \
									eat]\n"
# define NUM_ARGV_ERR		"❗1️⃣ Incorrect number of arguments, expected \
								one."
# define NO_INT_ARGV_ERR	"❗Argument is not integer value"
# define INT_NEG_ARGV_ERR	"❗Argument with negativ integer value. Forbidden."
# define PARAMS_ERR			"❗Incorrect parameteres."
# define ARG				"Argument "
# define INVALID			" is not valid."
# define NEGATIVE			" negative value."
# define VALUES_INVALID		"Values of some parameter are invalid."
# define INIT_ERR			"Initialization error."

# define INT_MAX			2147483647
# define INT_MIN			-2147483648

#endif
