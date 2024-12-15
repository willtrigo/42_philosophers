/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 18:42:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "routine/fork/fork.h"
#include "routine/handler/handler.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "utils/default.h"

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
		status = handler_mutex(&(*fork + i)->mutex, INIT, status);
	}
	return (status);
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
