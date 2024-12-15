/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 18:41:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_mutex.h"
#include "routine/monitor/monitor.h"
#include "routine/routine.h"
#include "utils/default.h"

int	monitor_init(
	t_monitor *monitor,
	int nbr_philos,
	int status
) {
	monitor->wait_to_eat = nbr_philos;
	monitor->death_philo = false;
	monitor->begin_time = DEFAULT;
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
	int			status;

	rt = (t_routine *)arg;
	status = EXIT_SUCCESS;
	monitor_permission(LOCK);
	monitor_log_permission(LOCK);
	(void)rt;
	monitor_permission(UNLOCK);
	monitor_log_permission(UNLOCK);
	if (status == EXIT_FAILURE)
		return ((void *)EXIT_FAILURE);
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
	int	status;

	status = EXIT_SUCCESS;
	status = handler_mutex(&monitor->mutex, DESTROY, status);
	if (status == EXIT_SUCCESS)
		status = handler_mutex(&monitor->log, DESTROY, status);
}
