/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 21:15:08 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>
# include <stdbool.h>
# include "routine/philo/philo.h"

typedef struct s_fork	t_fork;
struct s_fork
{
	int				id;
	_Atomic int		is_available;
	pthread_mutex_t	mutex;
};

int		fork_init(
			t_fork **fork,
			int nbr_philos,
			int status
			);

int		take_forks(
			t_philo *philo
			);

void	drop_forks(
			t_philo *philo
			);

void	fork_destroy(
			t_fork **fork,
			int nbr_philos
			);
#endif
