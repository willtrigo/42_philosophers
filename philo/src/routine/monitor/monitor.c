/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 15:57:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_mutex.h"
#include "routine/monitor/monitor.h"
#include "routine/monitor/monitor_internal.h"
#include "routine/routine.h"
#include "utils/default.h"
#include "utils/utils.h"

int	monitor_init(
	t_monitor *monitor,
	int nbr_philos,
	int status
) {
	monitor->wait_to_eat = nbr_philos;
	monitor->state = true;
	monitor->begin_time = DEFAULT;
	if (handler_mutex(&monitor->log, INIT, status) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (handler_mutex(&monitor->mutex, INIT, status) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (status);
}

void	*monitor_routine(
	void *arg
) {
	t_routine	*rt;
	int			status;
	int			i;
	long long	current_time;

	rt = (t_routine *)arg;
	status = EXIT_SUCCESS;
	while (monitor_state(GET, DEFAULT))
	{
		i = DEFAULT_INIT;
		current_time = get_time();
		while (++i < rt->info.number_of_philosophers)
			if (is_philo_death(rt, current_time, i))
				return (NULL);
		if (!is_philos_must_eat(rt))
			break ;
		usleep(MS_PER_SEC);
	}
	printf("all eat\n");
	if (status == EXIT_FAILURE)
		return ((void *)EXIT_FAILURE);
	return (NULL);
}

bool	monitor_state(
	int type,
	int value
) {
	if (type == SET)
	{
		monitor_permission(LOCK);
		rt()->monitor.state = value;
		monitor_permission(UNLOCK);
	}
	return (rt()->monitor.state);
}

void	monitor_destroy(
	t_monitor *monitor
) {
	int	status;

	status = EXIT_SUCCESS;
	status = handler_mutex(&monitor->mutex, DESTROY, status);
	if (status == EXIT_SUCCESS)
		status = handler_mutex(&monitor->log, DESTROY, status);
}
