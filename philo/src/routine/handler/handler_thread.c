/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:35:06 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 01:27:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include "routine/handler/handler.h"
#include "utils/default.h"
#include "utils/utils.h"

static int	handler_thread_create(
				int thread_status
				);

static int	handler_thread_join(
				int thread_status
				);

static int	handler_thread_detach(
				int thread_status
				);

int	handler_thread(
	pthread_t *th,
	t_handler type,
	void *(*func)(void *),
	void *arg
) {
	int		status;
	void	*thread_return;

	status = EXIT_SUCCESS;
	thread_return = NULL;
	if (type == CREATE)
		status = handler_thread_create(pthread_create(th, NULL, func, arg));
	else if (type == JOIN)
		status = handler_thread_join(pthread_join(*th, &thread_return));
	else if (type == DETACH)
		status = handler_thread_detach(pthread_detach(*th));
	if (thread_return != NULL)
		return (EXIT_FAILURE);
	return (status);
}

static int	handler_thread_create(
				int thread_status
) {
	int	status;

	status = EXIT_SUCCESS;
	if (thread_status != DEFAULT)
	{
		if (thread_status == EAGAIN)
			status = output_error("philo: thread create: " \
				"insufficient system resources to create another thread");
		else if (thread_status == EPERM)
			status = output_error("philo: thread create: " \
				"insufficient permissions for thread scheduling");
		else if (thread_status == EINVAL)
			status = output_error("philo: thread create: " \
				"invalid thread attributes");
		else if (thread_status == ENOMEM)
			status = output_error("philo: thread create: " \
				"insufficient memory to create the thread");
		else
			status = output_error("philo: thread create: " \
				"unknown error occurred during thread creation");
	}
	return (status);
}

static int	handler_thread_join(
				int thread_status
) {
	int	status;

	status = EXIT_SUCCESS;
	if (thread_status != DEFAULT)
	{
		if (thread_status == EDEADLK)
			status = output_error("philo: thread join: " \
				"deadlock detected (e.g., trying to join itself)");
		else if (thread_status == EINVAL)
			status = output_error("philo: thread join: " \
				"thread is not joinable or another thread is already " \
				"joinable it");
		else if (thread_status == ESRCH)
			status = output_error("philo: thread join: " \
				"no thread with the given ID found");
		else
			status = output_error("philo: thread join: " \
				"unknown error occurred during thread join");
	}
	return (status);
}

static int	handler_thread_detach(
				int thread_status
) {
	int	status;

	status = EXIT_SUCCESS;
	if (thread_status != DEFAULT)
	{
		if (thread_status == EINVAL)
			status = output_error("philo: thread detach: " \
				"invalid thread ID");
		else if (thread_status == ESRCH)
			status = output_error("philo: thread detach: " \
				"no thread found with the given ID");
		else
			status = output_error("philo: thread detach: " \
				"unknown error occurred during thread detaching");
	}
	return (status);
}
