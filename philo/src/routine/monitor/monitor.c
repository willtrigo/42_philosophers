/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:53:01 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:16:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "routine/monitor/fork.h"
#include "routine/monitor/monitor.h"
#include "routine/monitor/philo.h"
#include "utils/default.h"

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

void	monitor_destroy(
	t_monitor *monitor
) {
	if (monitor->philo)
		free(monitor->philo);
	if (monitor->fork)
		free(monitor->fork);
}
