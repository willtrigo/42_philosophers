/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:28:43 by dande-je          #+#    #+#             */
/*   Updated: 2024/12/17 11:28:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "routine/handler/handler.h"
#include "routine/monitor/monitor.h"
#include "routine/philo/philo.h"
#include "routine/routine.h"
#include "utils/default.h"
#include "utils/utils.h"

static void	is_philos_full(
				t_routine *rt,
				int philos_full,
				int i
				);

bool	is_philos_must_eat(
	t_routine *rt
) {
	int	philos_satisfied;

	philos_satisfied = DEFAULT;
	if (rt->info.number_of_times_each_philosopher_must_eat != DEFAULT_INIT)
	{
		while (rt->philo[philos_satisfied].must_eat == DEFAULT)
			philos_satisfied++;
		if (philos_satisfied == rt->info.number_of_philosophers)
		{
			monitor_permission(LOCK);
			rt->monitor.state = false;
			monitor_permission(UNLOCK);
			return (false);
		}
		is_philos_full(rt, DEFAULT, DEFAULT_INIT);
	}
	return (true);
}

bool	is_philo_death(
	t_routine *rt,
	long long current_time,
	int i
) {
	if (((current_time - rt->monitor.begin_time) >= rt->philo[i].time_to_die) \
		&& rt->philo[i].is_full == false)
	{
		output(rt->philo[i].id, current_time, "died");
		monitor_permission(LOCK);
		rt->monitor.state = false;
		monitor_permission(UNLOCK);
		return (true);
	}
	return (false);
}

static void	is_philos_full(
	t_routine *rt,
	int philos_full,
	int i
) {
	while (rt->philo[philos_full].is_full)
		philos_full++;
	if (philos_full == rt->info.number_of_philosophers)
	{
		while (+i < rt->info.number_of_philosophers)
		{
			philo_permission(LOCK, i);
			rt->philo[i].is_full = false;
			philo_permission(UNLOCK, i);
		}
	}
}
