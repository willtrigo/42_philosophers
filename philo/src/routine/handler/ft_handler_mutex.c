/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/12 15:30:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include "routine/handler/ft_handler.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"

static int	ft_handler_mutex_int(
				int mutex_status,
				int status
				);

static int	ft_handler_mutex_lock(
				int mutex_status,
				int status
				);

static int	ft_handler_mutex_unlock(
				int mutex_status,
				int status
				);

static int	ft_handler_mutex_destroy(
				int mutex_status,
				int status
				);

int	ft_handler_mutex(
	pthread_mutex_t *mutex,
	t_handler type,
	int status
) {
	if (status == EXIT_SUCCESS && type == INIT)
		status = ft_handler_mutex_int(pthread_mutex_init(mutex, \
			NULL), status);
	else if (status == EXIT_SUCCESS && type == LOCK)
		status = ft_handler_mutex_lock(pthread_mutex_lock(mutex), status);
	else if (status == EXIT_SUCCESS && type == UNLOCK)
		status = ft_handler_mutex_unlock(pthread_mutex_unlock(mutex), status);
	else if (status == EXIT_SUCCESS && type == DESTROY)
		status = ft_handler_mutex_destroy(pthread_mutex_destroy(mutex), status);
	return (status);
}

static int	ft_handler_mutex_int(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = ft_output_error("philo: mutex init: " \
				"invalid attribute parameter");
		else if (mutex_status == ENOMEM)
			status = ft_output_error("philo: mutex init: " \
				"insufficient memory to create mutex");
		else if (mutex_status == EAGAIN)
			status = ft_output_error("philo: mutex init: " \
				"insufficient system resources");
		else if (mutex_status == EBUSY)
			status = ft_output_error("philo: mutex init: " \
				"mutex is already initialized");
		else
			status = ft_output_error("philo: mutex init: " \
				"unknown error during mutex initialization");
	}
	return (status);
}

static int	ft_handler_mutex_lock(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = ft_output_error("philo: mutex lock: " \
				"invalid mutex");
		else if (mutex_status == EDEADLK)
			status = ft_output_error("philo: mutex lock: " \
				"deadlock condition detected");
		else
			status = ft_output_error("philo: mutex lock: " \
				"unknown error during mutex locking");
	}
	return (status);
}

static int	ft_handler_mutex_unlock(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = ft_output_error("philo: mutex unlock: " \
				"invalid mutex");
		else if (mutex_status == EPERM)
			status = ft_output_error("philo: mutex unlock: " \
				"mutex not owned by calling thread");
		else
			status = ft_output_error("philo: mutex unlock: " \
				"unknown error during mutex unlocking");
	}
	return (status);
}

static int	ft_handler_mutex_destroy(
				int mutex_status,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL)
			status = ft_output_error("philo: mutex destroy: " \
				"invalid mutex");
		else if (mutex_status == EBUSY)
			status = ft_output_error("philo: mutex destroy: " \
				"mutex is locked or referenced");
		else
			status = ft_output_error("philo: mutex destroy: " \
				"unknown error during mutex destruction");
	}
	return (status);
}
