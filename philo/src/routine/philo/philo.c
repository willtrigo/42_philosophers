/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 19:11:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "routine/handler/handler.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "routine/info/info.h"
#include "routine/monitor/monitor.h"
#include "routine/philo/philo.h"
#include "utils/default.h"
#include "utils/utils.h"

int	philo_init(
	t_philo **philo,
	int nbr_philos,
	t_info info,
	int status
) {
	const int	size = (nbr_philos + NULL_BYTE) * sizeof(t_philo);
	int			i;

	i = DEFAULT_INIT;
	if (handler_malloc((void **)philo, size, status, \
		"philo: malloc: fail to init philo malloc") != EXIT_SUCCESS)
		status = EXIT_FAILURE;
	memset(*philo, DEFAULT, size);
	while (status == EXIT_SUCCESS && ++i < nbr_philos)
	{
		(*philo + i)->time_to_last_eat = DEFAULT;
		(*philo + i)->id = i + DEFAULT_BEGIN;
		(*philo + i)->time_to_die = info.time_to_die;
		(*philo + i)->time_to_eat = info.time_to_eat;
		(*philo + i)->time_to_sleep = info.time_to_sleep;
		(*philo + i)->must_eat = info.number_of_times_each_philosopher_must_eat;
		status = handler_mutex(&(*philo + i)->mutex, INIT, status);
	}
	return (status);
}

void	*philo_routine(
			void *arg
) {
	int		status;
	t_philo	*philo;

	status = EXIT_SUCCESS;
	philo = (t_philo *)arg;
	handler_mutex(&philo->mutex, LOCK, EXIT_SUCCESS);
	monitor_permission(LOCK);
	monitor_log_permission(LOCK);
	output(philo->id, philo->time_to_last_eat, "philo alive");
	monitor_log_permission(UNLOCK);
	monitor_permission(UNLOCK);
	handler_mutex(&philo->mutex, UNLOCK, EXIT_SUCCESS);
	if (status == EXIT_FAILURE)
		return ((void *)EXIT_FAILURE);
	return (NULL);
}

void	philo_destroy(
	t_philo **philo,
	int nbr_philos
) {
	int	status;
	int	i;

	i = DEFAULT_INIT;
	status = EXIT_SUCCESS;
	while (status == EXIT_SUCCESS && ++i < nbr_philos)
	{
		status = handler_mutex(&(*philo + i)->mutex, DESTROY, status);
	}
	if (*philo)
		free(*philo);
}