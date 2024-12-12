/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:35:06 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 22:53:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include "routine/handler/ft_handler.h"
#include "routine/monitor/ft_philo.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"

static int	ft_handler_thread_create(
				int thread_status,
				int status
				);

static int	ft_handler_thread_join(
				int thread_status,
				int status
				);

int	ft_handler_thread(
	t_philo *philo,
	t_handler type,
	void *(*func)(void *),
	int status
) {
	if (status == EXIT_SUCCESS && type == CREATE)
		status = ft_handler_thread_create(pthread_create(&philo->thread, NULL, \
			func, philo), status);
	else if (status == EXIT_SUCCESS && type == JOIN)
		status = ft_handler_thread_join(pthread_join(philo->thread, NULL), \
			status);
	return (status);
}

static int	ft_handler_thread_create(
				int thread_status,
				int status
) {
	if (status == EXIT_SUCCESS && thread_status != DEFAULT)
	{
		if (thread_status == EAGAIN)
			status = ft_output_error("philo: thread create: " \
				"insufficient system resources to create another thread");
		else if (thread_status == EPERM)
			status = ft_output_error("philo: thread create: " \
				"insufficient permissions for thread scheduling");
		else if (thread_status == EINVAL)
			status = ft_output_error("philo: thread create: " \
				"invalid thread attributes");
		else if (thread_status == ENOMEM)
			status = ft_output_error("philo: thread create: " \
				"insufficient memory to create the thread");
		else
			status = ft_output_error("philo: thread create: " \
				"unknown error occurred during thread creation");
	}
	return (status);
}

static int	ft_handler_thread_join(
				int thread_status,
				int status
) {
	if (status == EXIT_SUCCESS && thread_status != DEFAULT)
	{
		if (thread_status == EDEADLK)
			status = ft_output_error("philo: thread join: " \
				"deadlock detected (e.g., trying to join itself)");
		else if (thread_status == EINVAL)
			status = ft_output_error("philo: thread join: " \
				"thread is not joinable or another thread is already " \
				"joinable it");
		else if (thread_status == ESRCH)
			status = ft_output_error("philo: thread join: " \
				"no thread with the given ID found");
		else
			status = ft_output_error("philo: thread join: " \
				"unknown error occurred during thread join");
	}
	return (status);
}
