/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:17 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 23:42:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

# include <pthread.h>
# include <stdbool.h>
# include "routine/handler/handler.h"

typedef struct s_monitor	t_monitor;
struct s_monitor
{
	_Atomic long long	begin_time;
	_Atomic int			wait_to_eat;
	_Atomic int			state;
	pthread_mutex_t		log;
	pthread_mutex_t		mutex;
	pthread_t			thread;
};

int		monitor_init(
			t_monitor *monitor,
			int wait_to_eat,
			int status
			);

void	*monitor_routine(
			void *arg
			);

int		monitor_wait_to_eat(
			int type
			);

bool	monitor_state(
			int type,
			int value
			);

void	monitor_permission(
			t_handler type
			);

void	monitor_log_permission(
			t_handler type
			);

void	monitor_destroy(
			t_monitor *monitor
			);

#endif
