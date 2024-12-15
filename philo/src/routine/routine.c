/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/15 13:14:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "routine/fork/fork.h"
#include "routine/handler/handler_thread.h"
#include "routine/info/info.h"
#include "routine/monitor/monitor.h"
#include "routine/philo/philo.h"
#include "routine/routine.h"
#include "utils/default.h"

t_routine	*rt(void)
{
	static t_routine	rt;

	return (&rt);
}

int	routine_init(
	char **argv,
	t_routine *rt,
	int status
) {
	int	i;
	int	nbr_philos;

	i = DEFAULT_INIT;
	nbr_philos = DEFAULT;
	status = info_init(argv, &rt->info, status);
	if (status == EXIT_SUCCESS)
	{
		nbr_philos = rt->info.number_of_philosophers;
		status = monitor_init(&rt->monitor, nbr_philos, status);
		while (status == EXIT_SUCCESS && ++i < nbr_philos)
			status = philo_init(rt->monitor.philo + i, i, rt->info, status);
		i = DEFAULT_INIT;
		while (status == EXIT_SUCCESS && ++i < nbr_philos)
			status = fork_init(rt->monitor.fork + i, status);
	}
	return (status);
}

int	routine_begin(
	t_routine *rt,
	int status
) {
	status = handler_thread(&rt->monitor.thread, CREATE, monitor_run, rt);
	if (status == EXIT_SUCCESS)
		status = handler_thread(&rt->monitor.thread, JOIN, NULL, NULL);
	return (status);
}

void	routine_destroy(
	t_routine *rt
) {
	monitor_destroy(&rt->monitor);
}
