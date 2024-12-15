/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 05:14:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "routine/info.h"
#include "routine/monitor/philo.h"
#include "routine/handler/handler_mutex.h"
#include "routine/monitor/monitor.h"
#include "utils/default.h"
#include "utils/utils.h"

int	philo_init(
	t_philo *philo,
	int i,
	t_info info,
	int status
) {
	philo->time_to_last_eat = DEFAULT;
	philo->id = i + DEFAULT_BEGIN;
	philo->time_to_die = info.time_to_die;
	philo->time_to_eat = info.time_to_eat;
	philo->time_to_sleep = info.time_to_sleep;
	philo->must_eat = info.number_of_times_each_philosopher_must_eat;
	status = handler_mutex(&philo->mutex, INIT, status);
	return (status);
}

void	*philo_routine(
			void *arg
) {
	t_philo	*philo;

	philo = (t_philo *)arg;
	handler_mutex(&philo->mutex, LOCK, EXIT_SUCCESS);
	monitor_permission(LOCK);
	monitor_log_permission(LOCK);
	output(philo->id, philo->time_to_last_eat, "philo alive");
	monitor_log_permission(UNLOCK);
	monitor_permission(UNLOCK);
	handler_mutex(&philo->mutex, UNLOCK, EXIT_SUCCESS);
	return (NULL);
}
