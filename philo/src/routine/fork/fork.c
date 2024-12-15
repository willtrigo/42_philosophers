/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:34 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 13:53:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "routine/fork/fork.h"
#include "routine/handler/handler_malloc.h"
#include "routine/handler/handler_mutex.h"
#include "utils/default.h"

int	fork_init(
	t_fork *fork,
	int nbr_philos,
	int status
) {
	int	i;

	i = DEFAULT_INIT;
	if (handler_malloc((void **)&fork, \
		nbr_philos * sizeof(t_fork), status, \
		"philo: malloc: fail to init fork malloc") != EXIT_SUCCESS)
		status = EXIT_FAILURE;
	while (status == EXIT_SUCCESS && ++i < nbr_philos)
		status = handler_mutex(&fork->mutex, INIT, status);
	return (status);
}

void	fork_destroy(
	t_fork *fork
) {
	if (fork)
		free(fork);
}
