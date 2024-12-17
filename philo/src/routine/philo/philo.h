/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:40 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 09:50:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include "routine/handler/handler.h"
# include "routine/info/info.h"

typedef struct s_philo	t_philo;
struct s_philo
{
	_Atomic long long	time_to_last_eat;
	_Atomic int			must_eat;
	_Atomic int			is_full;
	int					id;
	_Atomic int			time_to_die;
	_Atomic int			time_to_eat;
	_Atomic int			time_to_sleep;
	int					right_hand;
	int					left_hand;
	pthread_t			thread;
	pthread_mutex_t		mutex;
};

int		philo_init(
			t_philo **philo,
			int nbr_philos,
			t_info info,
			int status
			);

void	*philo_routine(
			void *arg
			);

void	philo_permission(
			t_handler type,
			int id
			);

void	philo_destroy(
			t_philo **philo,
			int nbr_philos
			);

#endif
