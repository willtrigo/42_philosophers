/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:16:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include <stdbool.h>
# include <pthread.h>
# include "routine/monitor/fork.h"
# include "routine/monitor/philo.h"

typedef struct s_monitor	t_monitor;
struct s_monitor
{
	long long		begin_time;
	int				wait_to_eat;
	bool			death_philo;
	t_philo			*philo;
	t_fork			*fork;
	pthread_mutex_t	log;
	pthread_mutex_t	mutex;
	pthread_t		thread;
};

int		monitor_init(
			t_monitor *monitor,
			int nbr_philos,
			int status
			);

void	monitor_destroy(
			t_monitor *monitor
			);

#endif