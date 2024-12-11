/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:21:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/11 16:30:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include "routine/handler/ft_handler.h"
#include "utils/ft_default.h"
#include "utils/ft_utils.h"

static int	ft_handler_mutex_error(
				int mutex_status,
				t_handler type,
				int status
				);

int	ft_handler_mutex(
	pthread_mutex_t *mutex,
	t_handler type,
	int status
) {
	if (status == EXIT_SUCCESS && type == INIT)
		status = ft_handler_mutex_error(pthread_mutex_init(mutex, \
			NULL), type, status);
	return (status);
}

static int	ft_handler_mutex_error(
				int mutex_status,
				t_handler type,
				int status
) {
	if (status == EXIT_SUCCESS && mutex_status != DEFAULT)
	{
		if (mutex_status == EINVAL && type == INIT)
			status = ft_output_error("philo: mutex: value " \
				"specified at attribute is invalid");
	}
	return (status);
}
