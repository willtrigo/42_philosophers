/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/13 12:08:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/info.h"
#include "routine/routine.h"
#include "routine/monitor/fork.h"
#include "routine/monitor/monitor.h"
#include "routine/monitor/philo.h"
#include "utils/default.h"

t_routine	*routine(void)
{
	static t_routine	routine;

	return (&routine);
}

int	routine_init(
	char **argv,
	t_routine *routine,
	int status
) {
	int	i;

	i = DEFAULT_INIT;
	status = info_init(argv, &routine->info, status);
	if (status == EXIT_SUCCESS)
	{
		status = monitor_init(&routine->monitor, \
			routine->info.number_of_philosophers, status);
		while (status == EXIT_SUCCESS \
			&& ++i < routine->info.number_of_philosophers)
			status = philo_init(routine->monitor.philo + i, i, \
				routine->info, status);
		i = DEFAULT_INIT;
		while (status == EXIT_SUCCESS \
			&& ++i < routine->info.number_of_philosophers)
			status = fork_init(routine->monitor.fork + i, status);
	}
	return (status);
}

void	routine_destroy(
	t_routine *routine
) {
	monitor_destroy(&routine->monitor);
}
