/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 05:15:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "routine/handler/handler_thread.h"
#include "routine/monitor/fork.h"
#include "routine/monitor/monitor.h"
#include "routine/monitor/philo.h"
#include "routine/routine.h"
#include "utils/default.h"
#include "utils/utils.h"

int	monitor_init(
	t_monitor *monitor,
	int nbr_philos,
	int status
) {
	monitor->wait_to_eat = nbr_philos;
	monitor->death_philo = false;
	monitor->begin_time = DEFAULT;
	if (handler_malloc((void **)&monitor->philo, \
		nbr_philos * sizeof(t_philo), status, \
		"philo: malloc: fail to init philo malloc") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (handler_malloc((void **)&monitor->fork, \
		nbr_philos * sizeof(t_fork), status, \
		"philo: malloc: fail to init fork malloc") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (handler_mutex(&monitor->log, INIT, status) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (handler_mutex(&monitor->mutex, INIT, status) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (status);
}

void	*monitor_run(
	void *arg
) {
	t_routine	*rt;
	int			i;
	int			status;

	rt = (t_routine *)arg;
	i = DEFAULT_INIT;
	status = EXIT_SUCCESS;
	monitor_permission(LOCK);
	monitor_log_permission(LOCK);
	rt->monitor.begin_time = get_time();
	while (status == EXIT_SUCCESS && ++i < rt->info.number_of_philosophers)
	{
		rt->monitor.philo[i].time_to_last_eat = rt->monitor.begin_time;
		status = handler_thread(&rt->monitor.philo[i].thread, CREATE, \
			philo_routine, &rt->monitor.philo[i]);
	}
	while (status == EXIT_SUCCESS && ++i < rt->info.number_of_philosophers)
		status = handler_thread(&rt->monitor.philo[i].thread, JOIN, NULL, NULL);
	monitor_permission(UNLOCK);
	monitor_log_permission(UNLOCK);
	if (status == EXIT_FAILURE)
		return ((void *)EXIT_FAILURE);
	while (1)
		;
	return (NULL);
}

void	monitor_permission(
	t_handler type
) {
	if (type == LOCK)
		handler_mutex(&rt()->monitor.mutex, LOCK, EXIT_SUCCESS);
	if (type == UNLOCK)
		handler_mutex(&rt()->monitor.mutex, UNLOCK, EXIT_SUCCESS);
}

void	monitor_log_permission(
	t_handler type
) {
	if (type == LOCK)
		handler_mutex(&rt()->monitor.log, LOCK, EXIT_SUCCESS);
	if (type == UNLOCK)
		handler_mutex(&rt()->monitor.log, UNLOCK, EXIT_SUCCESS);
}

void	monitor_destroy(
	t_monitor *monitor
) {
	if (monitor->philo)
		free(monitor->philo);
	if (monitor->fork)
		free(monitor->fork);
}
