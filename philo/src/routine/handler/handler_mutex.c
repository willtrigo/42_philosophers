/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:17:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include "routine/handler/handler.h"
#include "utils/default.h"
#include "utils/utils.h"

static int	handler_mutex_int(
				int mutex_status,
				int status
				);

static int	handler_mutex_lock(
				int mutex_status,
				int status
				);

static int	handler_mutex_unlock(
				int mutex_status,
				int status
				);

static int	handler_mutex_destroy(
				int mutex_status,
				int status
				);

int	handler_mutex(
	pthread_mutex_t *mutex,
	t_handler type,
	int status
) {
	if (status == EXIT_SUCCESS && type == INIT)
		status = handler_mutex_int(pthread_mutex_init(mutex, \
			NULL), status);
	else if (status == EXIT_SUCCESS && type == LOCK)
		status = handler_mutex_lock(pthread_mutex_lock(mutex), status);
	else if (status == EXIT_SUCCESS && type == UNLOCK)
		status = handler_mutex_unlock(pthread_mutex_unlock(mutex), status);
	else if (status == EXIT_SUCCESS && type == DESTROY)
		status = handler_mutex_destroy(pthread_mutex_destroy(mutex), status);
	return (status);
}

static int	handler_mutex_int(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = output_error("philo: mutex init: " \
				"invalid attribute parameter");
		else if (mutex_status == ENOMEM)
			status = output_error("philo: mutex init: " \
				"insufficient memory to create mutex");
		else if (mutex_status == EAGAIN)
			status = output_error("philo: mutex init: " \
				"insufficient system resources");
		else if (mutex_status == EBUSY)
			status = output_error("philo: mutex init: " \
				"mutex is already initialized");
		else
			status = output_error("philo: mutex init: " \
				"unknown error during mutex initialization");
	}
	return (status);
}

static int	handler_mutex_lock(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = output_error("philo: mutex lock: " \
				"invalid mutex");
		else if (mutex_status == EDEADLK)
			status = output_error("philo: mutex lock: " \
				"deadlock condition detected");
		else
			status = output_error("philo: mutex lock: " \
				"unknown error during mutex locking");
	}
	return (status);
}

static int	handler_mutex_unlock(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = output_error("philo: mutex unlock: " \
				"invalid mutex");
		else if (mutex_status == EPERM)
			status = output_error("philo: mutex unlock: " \
				"mutex not owned by calling thread");
		else
			status = output_error("philo: mutex unlock: " \
				"unknown error during mutex unlocking");
	}
	return (status);
}

static int	handler_mutex_destroy(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = output_error("philo: mutex destroy: " \
				"invalid mutex");
		else if (mutex_status == EBUSY)
			status = output_error("philo: mutex destroy: " \
				"mutex is locked or referenced");
		else
			status = output_error("philo: mutex destroy: " \
				"unknown error during mutex destruction");
	}
	return (status);
}
