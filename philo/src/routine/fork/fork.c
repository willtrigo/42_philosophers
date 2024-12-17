/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 16:12:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "routine/fork/fork.h"
#include "routine/handler/handler.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "routine/monitor/monitor.h"
#include "routine/philo/philo.h"
#include "routine/routine.h"
#include "utils/default.h"
#include "utils/utils.h"

static int	take_fork(void);

int	fork_init(
	t_fork **fork,
	int nbr_philos,
	int status
) {
	const int	size = (nbr_philos + NULL_BYTE) * sizeof(t_fork);
	int			i;

	i = DEFAULT_INIT;
	if (handler_malloc((void **)fork, size, status, \
		"philo: malloc: fail to init fork malloc") != EXIT_SUCCESS)
		status = EXIT_FAILURE;
	memset(*fork, DEFAULT, size);
	while (status == EXIT_SUCCESS && ++i < nbr_philos)
	{
		(*fork + i)->id = i;
		(*fork + i)->is_available = true;
		status = handler_mutex(&(*fork + i)->mutex, INIT, status);
	}
	return (status);
}

int	take_forks(
	t_philo *philo
) {
	const long long	current_time = get_time();

	monitor_permission(LOCK);
	if (philo->right_hand == DEFAULT_INIT)
	{
		philo->right_hand = take_fork();
		if (philo->right_hand != DEFAULT_INIT)
			output(philo->id, current_time, "has taken a fork");
	}
	if (philo->left_hand == DEFAULT_INIT)
	{
		philo->left_hand = take_fork();
		if (philo->left_hand != DEFAULT_INIT)
			output(philo->id, current_time, "has taken a fork");
	}
	monitor_permission(UNLOCK);
	return (EXIT_SUCCESS);
}

void	drop_forks(
	t_philo *philo
) {
	handler_mutex(&rt()->fork[philo->right_hand].mutex, LOCK, EXIT_SUCCESS);
	rt()->fork[philo->right_hand].is_available = true;
	handler_mutex(&rt()->fork[philo->right_hand].mutex, UNLOCK, EXIT_SUCCESS);
	philo->right_hand = DEFAULT_INIT;
	handler_mutex(&rt()->fork[philo->left_hand].mutex, LOCK, EXIT_SUCCESS);
	rt()->fork[philo->left_hand].is_available = true;
	handler_mutex(&rt()->fork[philo->left_hand].mutex, UNLOCK, EXIT_SUCCESS);
	philo->left_hand = DEFAULT_INIT;
}

void	fork_destroy(
	t_fork **fork,
	int nbr_philos
) {
	int	status;
	int	i;

	i = DEFAULT_INIT;
	status = EXIT_SUCCESS;
	while (status == EXIT_SUCCESS && ++i < nbr_philos)
		status = handler_mutex(&(*fork + i)->mutex, DESTROY, status);
	if (*fork)
		free(*fork);
}

static int	take_fork(void)
{
	int	i;

	i = DEFAULT_INIT;
	if (rt()->info.number_of_philosophers == DEFAULT_BEGIN)
	{
		if (rt()->philo[DEFAULT].right_hand == DEFAULT_INIT)
		{
			handler_mutex(&rt()->fork[DEFAULT].mutex, LOCK, EXIT_SUCCESS);
			rt()->fork[DEFAULT].is_available = false;
			handler_mutex(&rt()->fork[DEFAULT].mutex, UNLOCK, EXIT_SUCCESS);
			return (DEFAULT);
		}
	}
	while (DEFAULT_BEGIN && ++i < rt()->info.number_of_philosophers)
	{
		if (rt()->fork[i].is_available)
		{
			handler_mutex(&rt()->fork[i].mutex, LOCK, EXIT_SUCCESS);
			rt()->fork[i].is_available = false;
			handler_mutex(&rt()->fork[i].mutex, UNLOCK, EXIT_SUCCESS);
			return (i);
		}
	}
	return (DEFAULT_INIT);
}
