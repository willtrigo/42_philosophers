/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:40 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 15:51:42 by dande-je         ###   ########.fr       */
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
	long long		time_to_last_eat;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				right_hand;
	int				left_hand;
	bool			is_dead;
	pthread_t		thread;
	pthread_mutex_t	mutex;
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
