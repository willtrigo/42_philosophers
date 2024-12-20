/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:51:30 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/18 08:08:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "routine/fork/fork.h"
#include "routine/handler/handler.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "routine/info/info.h"
#include "routine/philo/philo.h"
#include "routine/monitor/monitor.h"
#include "routine/philo/philo_internal.h"
#include "utils/default.h"

static bool	philo_is_able(
				t_philo *philo,
				int validation_type
				);

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
		(*philo + i)->right_hand = DEFAULT_INIT;
		(*philo + i)->left_hand = DEFAULT_INIT;
		(*philo + i)->is_full = false;
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
	while (monitor_state(GET, DEFAULT))
	{
		if (!philo->is_full && philo->must_eat != DEFAULT)
		{
			if (philo_is_able(philo, EQUAL))
				take_forks(philo);
			if (((monitor_wait_to_eat(GET) == DEFAULT_INIT) \
				|| (monitor_wait_to_eat(GET) > DEFAULT)) && \
				philo_is_able(philo, DIFF))
			{
				philo_eat(philo);
				philo_sleep(philo);
				philo_think(philo);
			}
		}
		usleep(MS_DEFAULT);
	}
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

static bool	philo_is_able(
	t_philo *philo,
	int validation_type
) {
	if (validation_type == EQUAL)
	{
		if (philo->right_hand == DEFAULT_INIT \
			|| philo->left_hand == DEFAULT_INIT)
			return (true);
	}
	else
	{
		if (philo->right_hand != DEFAULT_INIT \
			&& philo->left_hand != DEFAULT_INIT)
			return (true);
	}
	return (false);
}
