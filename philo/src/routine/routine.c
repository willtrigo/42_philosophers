/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 07:18:28 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/16 14:41:09 by dande-je         ###   ########.fr       */
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
#include "utils/utils.h"

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
	int	nbr_philos;

	nbr_philos = DEFAULT;
	status = info_init(argv, &rt->info, status);
	if (status == EXIT_SUCCESS)
	{
		nbr_philos = rt->info.number_of_philosophers;
		status = fork_init(&rt->fork, nbr_philos, status);
		if (status == EXIT_SUCCESS)
			status = philo_init(&rt->philo, nbr_philos, rt->info, status);
		if (status == EXIT_SUCCESS)
			status = monitor_init(&rt->monitor, nbr_philos, status);
	}
	return (status);
}

int	routine_begin(
	t_routine *rt,
	int status
) {
	int	i;

	i = DEFAULT_INIT;
	rt->monitor.begin_time = get_time();
	status = handler_thread(&rt->monitor.thread, CREATE, monitor_routine, rt);
	while (status == EXIT_SUCCESS && ++i < rt->info.number_of_philosophers)
	{
		rt->philo[i].time_to_last_eat = rt->monitor.begin_time;
		status = handler_thread(&rt->philo[i].thread, CREATE, \
			philo_routine, &rt->philo[i]);
	}
	i = DEFAULT_INIT;
	while (status == EXIT_SUCCESS && ++i < rt->info.number_of_philosophers)
		status = handler_thread(&rt->philo[i].thread, JOIN, NULL, NULL);
	if (status == EXIT_SUCCESS)
		status = handler_thread(&rt->monitor.thread, JOIN, NULL, NULL);
	return (status);
}

void	routine_destroy(
	t_routine *rt
) {
	fork_destroy(&rt->fork, rt->info.number_of_philosophers);
	philo_destroy(&rt->philo, rt->info.number_of_philosophers);
	monitor_destroy(&rt->monitor);
}
